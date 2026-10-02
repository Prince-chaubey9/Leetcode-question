// same as 583 
// given string ko reverse kiya 
// dono m jitne ele comon h use vo find kiya 
// s k jitne ele common nhi utne hi add krne honge palindrom banane k liy 
// isme ele ko s m kahi bhi insert kr skte h 

class Solution {
public:
     int LCS(string x, string y) { // get size of longest common subsequence
        int n = x.size(), m = y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i-1] == y[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        int ans= LCS(s,k);
        ans= s.size()-ans; // jitne ele add krne h vo honge no of uncommon ele 
        return ans;
        
    }
};