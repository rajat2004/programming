import pandas as pd

data = pd.read_csv("Datasets/FP_Part-2_test.csv", encoding= 'unicode_escape')
# print(data)

# Group items bought by the same customer
# Strip leading and trailing whitespaces from each item description
cleaned_data = data.groupby("CustomerID")["Description"].apply(lambda x: ",".join(x.str.strip())).reset_index()
# print(cleaned_data)

with open("formatted.csv", "w") as fout:
    fout.write(cleaned_data['Description'].str.cat(sep="\n"))
    fout.close()
