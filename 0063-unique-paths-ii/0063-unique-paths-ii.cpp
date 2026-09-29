// using DP method top down approach 


class Solution {
public:
int top_down(vector<vector<int>>& nums,int row,int clm,int m, int n,vector<vector<int>>& dp){
     if(row>=m || clm>=n) return 0; // agr grid se bahr to return 
    if(nums[row][clm]==1) return 0; // agr obstacle h to koi way nhi hoga us point se 
    if(row==m-1 && clm== n-1) return 1; // last indx pr pahuch gye means y ak way h 
   

    if(dp[row][clm]!=-1) return dp[row][clm]; // agr is indx k liy check kr chuke h 
    dp[row][clm]= top_down(nums,row+1,clm,m,n,dp)+top_down(nums,row,clm+1,m,n,dp); 
    // total way from row , clm = way from row+1, clm and row, clm+1 
    // updat ethis in dp array 
    return dp[row][clm];
}
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m= nums.size(), n= nums[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return top_down(nums,0,0,m,n,dp);

    }
};