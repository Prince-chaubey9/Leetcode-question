class Solution {
public:
    int helper(vector<int>& cost, int indx, vector<int>& dp) {
        if (indx == 0 || indx == 1) {
            return cost[indx];
        }
        if (indx < 0)
            return 0;
        if (dp[indx] != -1) // agr kisi indx ki cost nikal chuke h to usi ko
                            // return kro , dobara check nhi krn a

            return dp[indx];
        dp[indx] = cost[indx] +min(helper(cost, indx - 1, dp), helper(cost, indx - 2, dp));
        // kisi tk pahuchne ki cost = cost[i]+usase pahle tk ki mn cost
        return dp[indx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
    }
};
// last se first indx tk move kia