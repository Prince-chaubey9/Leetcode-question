class Solution {
public:
    int sum(vector<vector<int>>& tri, int ro, int clm, vector<vector<int>>& dp){
        if(clm>=dp.size()) return INT_MAX; // agr clmlimit se bahar chala jay
        if(ro==dp.size()) return 0; // agr ro limit se bahar means sabhi row k sum a chuka h 

        if(dp[ro][clm]!=INT_MAX) return dp[ro][clm]; // agr pahle se h 

        int ans= min(sum(tri,ro+1,clm,dp),sum(tri, ro+1,clm+1,dp)); // sabhi condi k liy check kia
        dp[ro][clm]= tri[ro][clm]+ans;
        return dp[ro][clm];
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n= tri.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return sum(tri,0,0,dp);

    }
};