import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    employee.drop_duplicates(subset=['salary'],inplace=True) # drop all duplicate values store return table in new or inplace =True to change in original table
    if N>len(employee) or N<=0: # if ask N is out of range 
        return pd.DataFrame({f'getNthHighestSalary({N})':[None]}) # colum name and values pas in list 
    employee=employee.sort_values('salary',ascending=False) # sort  based on salary
    salary=employee.iloc[N-1]['salary'] # call iloc so can acces nth row from above bcz it access by index not lebel
    x=pd.DataFrame({f'getNthHighestSalary({N})':[salary]}) # store return value in new dataframe 
    return x # return that