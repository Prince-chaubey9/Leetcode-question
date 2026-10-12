import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    products= products[(products['low_fats']=='Y') & (products['recyclable']=='Y')]['product_id']
    ans=pd.DataFrame(products)
    return ans