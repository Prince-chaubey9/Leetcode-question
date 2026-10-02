// TABULATION DP y memorization DP k use se longest comon subsequence ki length find kro
// ab dono string m jo total no of uncomon ele h utne hi ele insert or delet krne pr 
// dono string same ho jaygi

class Solution {
public:
    int LCS(string x, string y) {
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
    
    int minDistance(string word1, string word2) {
        int s= LCS(word1,word2);
        int ans = word1.size()+word2.size()-2*s;
        // str1 , str 2 k total uncomon ele 
        return ans;
    }
};