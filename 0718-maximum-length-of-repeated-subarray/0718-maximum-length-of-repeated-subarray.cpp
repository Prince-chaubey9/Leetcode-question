// tabulation method

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(),m= nums2.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){ // agr char same h to use count ko inc kr d0
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]); // hhr bar ans se compare kr k ans ki value ko update kro
                }
            }
        }
        return ans;
    }
};