from pyspark import SparkContext
from pyspark.mllib.recommendation import ALS, Rating

import math

sc = SparkContext.getOrCreate()

alstext = sc.textFile("Datasets/ALS.txt")
print("Total rows in file: ", alstext.count())

ratings = alstext.flatMap(lambda l: [l.split('::')])
# print(ratings.collect())
ratings = ratings.map(lambda l: Rating(int(l[0]), int(l[1]), float(l[2])))

train, test = ratings.randomSplit([0.8, 0.2], seed=12345)
print("Training data size: ", train.count())
print("Test data size: ", test.count())

# Build the recommendation model using Alternating Least Squares
rank = 30
numIterations = 20
model = ALS.train(ratings, rank, numIterations, lambda_=1e-4)

testdata = test.map(lambda r: (r[0], r[1]))
# print(testdata.count())

# Get model predictions
predictions = model.predictAll(testdata).map(lambda r: ((r[0], r[1]), r[2]))
# Create tuple of actual and predicted ratings
ratesAndPreds = test.map(lambda r: ((r[0], r[1]), r[2])).join(predictions)
# print(ratesAndPreds.collect())

MSE = ratesAndPreds.map(lambda r: (r[1][0] - r[1][1])**2).mean()
# print(MSE)
print("Root Mean Squared Error = " + str(math.sqrt(MSE)))

# model.save(sc, "ALS_model")
# predictions.coalesce(1).saveAsTextFile("ALS_out.txt")
