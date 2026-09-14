// DP 
// ism e ak 2D vector banaya jisme hr ak index k ly ak hi bar m note kr liya k wah ase kitne path j rhe h to recursive call m bar bar usi iindex k liy calculate nhi krna 

class Solution {
public:
    int helper(int ro, int clm, int endr, int endclm, vector<vector<int>>& dp) {
        if (ro == endr && clm == endclm)// agr last indx tk pahuch gye means path ban gya 
            return 1;
        if (ro > endr || clm > endclm) // agr sheet se bahar h gye to no path 
            return 0;
        if (dp[ro][clm] != -1)
            return dp[ro][clm];// agr pahle hi check kr chuke h to dobara check krne ki jrurat nhi h 
        dp[ro][clm] = (helper(ro + 1, clm, endr, endclm,dp) + helper(ro, clm + 1, endr, endclm,dp));
        // agr ro,clm indx k liy path check nhi kia h to check kro aur use return kro 
        return dp[ro][clm];
    }
    int uniquePaths(int m, int n) {
        if(m==1&& n==1) return 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 1, m - 1, n - 1, dp) + helper(1, 0, m - 1, n - 1, dp);
    }
};