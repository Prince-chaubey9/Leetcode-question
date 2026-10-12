import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    employee['departmentName'] = employee['departmentId'].map(
        department.set_index('id')['name']
    )

    employee['rank'] = employee.groupby('departmentId')['salary'].rank(
        method='dense', ascending=False
    )

    employee = employee[employee['rank'] <= 3]

    return employee[['departmentName', 'name', 'salary']].rename(
        columns={'departmentName': 'Department', 'name': 'Employee', 'salary': 'Salary'}
    )