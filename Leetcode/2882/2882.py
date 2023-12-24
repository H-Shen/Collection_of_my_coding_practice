import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    uniqueEmails = set()
    customerIdsToRemove = list()
    for _, row in customers.iterrows():
        if row['email'] in uniqueEmails:
            customerIdsToRemove.append(row['customer_id'])
        else:
            uniqueEmails.add(row['email'])
    df = customers[~customers['customer_id'].isin(customerIdsToRemove)]
    return df