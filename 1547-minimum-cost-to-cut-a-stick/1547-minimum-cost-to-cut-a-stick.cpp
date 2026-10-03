class Solution {
public:
    int solve(vector<int>& cuts, int i, int j,vector<vector<int>>&dp) {
        if (i+1== j) // jb koi length n bache cut krne ko
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for (int k = i+1; k < j; k++) { // jo array indx pass hue inme se sabke sath check kro 
           int x= cuts[j] - cuts[i] + solve(cuts, i, k,dp) + solve(cuts, k, j,dp);
          // j,i cuts array m indx  h jo jisase cuts[j]-cuts[i] curent stick ki length h
          // k bhi cuts k indx h jo cuts k ele se stick m cut point bata rha h 
           ans=min(ans,x);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n); // push length of stick in cuts array
        cuts.insert(cuts.begin(), 0); // starting point of stick
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(cuts, 0, cuts.size() - 1,dp); // gives ans
    }
};