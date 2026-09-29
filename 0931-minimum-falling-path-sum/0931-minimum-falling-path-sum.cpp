class Solution {
public:
    int sum(vector<vector<int>>& mat, int ro, int clm, vector<vector<int>>&dp){
        if(clm<0 || clm>=dp[0].size()){ // agr out of colum chala jay
            return INT_MAX;
        }
        if(ro==mat.size()) return 0; // agr sabhi ro check ho gyi aur akhiri ro se age nikal gye to 
        if(dp[ro][clm]!=INT_MAX){ // agr pahle se h to 
            return dp[ro][clm];
        }
        int ans=min({sum(mat,ro+1,clm,dp),sum(mat,ro+1,clm+1,dp),sum(mat,ro+1,clm-1,dp)});
        // teeno condition check kiya 
        dp[ro][clm]= mat[ro][clm]+ans;// ans m current indx ki value add ki 
        return dp[ro][clm]; // dp[ro][clm] return 
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m= mat.size(), n= mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        int ans= INT_MAX;
        for(int i=0; i<n;i++){ // 0th ro k sabhi elle k liy check kiy 
            ans=min(ans,sum(mat,0,i,dp));
        }
        return ans;
    }
};