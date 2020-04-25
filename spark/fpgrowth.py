from pyspark import SparkContext
from pyspark.mllib.fpm import FPGrowth

sc = SparkContext.getOrCreate()

# data = sc.textFile("Datasets/FP_Part-1.csv")
data = sc.textFile("formatted.csv")
print("Total rows in file: ", data.count())

# Remove duplicate entries in a row
transactions = data.map(lambda line: line.split(","))
unique = transactions.map(lambda x: list(set(x)) )

model = FPGrowth.train(unique, minSupport=0.1)
# Sort items based on frequency
result = sorted(model.freqItemsets().collect(), reverse=True, key=lambda x: x[1])

for fi in result:
    print(fi)
