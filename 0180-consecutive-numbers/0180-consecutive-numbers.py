import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    count=1
    ConsecutiveNums=[]
    for n in range(1,len(logs)):
        if logs.iloc[n]['num']==logs.iloc[n-1]['num'] and logs.iloc[n]['num'] not in ConsecutiveNums :
            count+=1
            if count==3:
                ConsecutiveNums.append(logs.iloc[n]['num'])
        else:
            count=1
    ans= pd.DataFrame({'ConsecutiveNums':ConsecutiveNums })
    return ans 
# take first ele and start fron second 
# check previous ele is same or not , if same then chek is ele ko ans list m le chuke h y nhi agr nhi to age move further else skip
# agr previous k equal nhi h to skipp 
# agr teen line m h to ans m push kia 