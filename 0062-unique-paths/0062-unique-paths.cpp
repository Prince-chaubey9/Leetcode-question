// TABULATION METHOD 
// isme i, j indx se jane wale path = path at uper box+path at previous box 

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(i!=0&& j!=0){
                    dp[i][j]= dp[i-1][j]+dp[i][j-1]; // ak row uper same colum and same row ak previous colum
                }else if(i==0 && j!=0){
                    dp[i][j]= dp[i][j-1]; // previous culum
                }else if(j==0&& i!=0){
                    dp[i][j]= dp[i-1][j]; // previous row
                }
            }
        }
        return dp[m-1][n-1];
    }
};