class Solution {
public:
    int solve(string & s, string &t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.size()) {
            return 1;
        }
        if (i >= s.size())
            return 0;
        if (dp[i][j] != -1) // agr pahle hi check kr chuke h to 
            return dp[i][j];
        int temp = 0;
        if (s[i] == t[j]) {   // agr same h to include kr sakte h 
            temp = solve(s, t, i + 1, j + 1,dp);
        }
        dp[i][j] = temp + solve(s, t, i + 1, j,dp);  // same ho y n ho not include to hoga hi once 
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        if(s.size()<t.size()) return 0;
        int n = s.size();
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        solve(s, t, 0, 0,dp);
        return dp[0][0];
    }
};