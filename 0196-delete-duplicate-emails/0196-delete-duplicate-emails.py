import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    person.sort_values('id', inplace=True)
    person.drop_duplicates(subset='email',keep='first',inplace=True)
    # isme dataframe se un rows ko drop kr rhe h jinke email column m duplicate values h 
    # keep =first se fisrt occurance ko rakhega baki sabhi ko hata dega 
    # keep= last se laast occurance ko rakheg a
    # keep= false se sabhi occurance hata dega 