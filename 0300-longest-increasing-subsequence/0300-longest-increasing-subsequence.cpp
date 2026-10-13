// use 2D ARRAY DP method for TLE 

class Solution {
public:
    int solve(vector<int>&nums, int i, int j,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        int not_take=solve(nums,i+1,j,dp); // not include 
        if(nums[i]>nums[j]){ // agr last include ele se   grtr h to include krenge
             take=1+solve(nums,i+1,i,dp);
        }
        return dp[i][j]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN); // add new ele int mint for 2d array DP algo
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,1,0,dp);
    }
};