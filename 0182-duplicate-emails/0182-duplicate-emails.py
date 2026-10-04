import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    Emails=[]
    person['duplicate']= person['email'].duplicated() # made a new colum for every email value it has duplicate or not 
    for n in range(0,len(person)):
        if person.loc[n,'duplicate']== True and person.loc[n,'email'] not in Emails:
            Emails.append(person.loc[n,'email'])
    # sabhi row ko ak ak kr visit agr vo duplicate h to check kro Email list m h y nhi agr nhi to add kr do 
    ans= pd.DataFrame({'Email':Emails}) # Email list k dataFrame banaya 
    return ans 