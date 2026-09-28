class Solution {
public:
int helper(vector<vector<int>>& grid, int row, int clm, int m , int n,vector<vector<int>>& dp){
    if(row==m-1 && clm== n-1){ // agr crnt row and clm don last m h to 
        return grid[m-1][n-1];
    }
    if(row>=m || clm>=n){ // agr row y clm range se bahar chale gye
        return INT_MAX;
    }
    if(dp[row][clm]!=-1) return dp[row][clm]; // agr row, clm indx k liy compute kr chuke h 
    dp[row][clm]= grid[row][clm]+min(helper(grid,row,clm+1,m,n,dp),helper(grid,row+1,clm,m,n,dp)); // kisi indx se m,n tk k min = uske right se aur down se m, tk k min plus vo khd 
    return dp[row][clm];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(grid,0,0,m,n,dp);
    }
};