class Solution {
public:
    int solve(vector<int>& prices, int i, int k,int fee,vector<vector<int>>& dp) {
        if (i >= prices.size()) { // all transectioned completed
            return 0;
        }
        if (dp[i][k] != -1)
            return dp[i][k];

        int x, y= INT_MIN;
        if (k % 2 == 0) { // can buy only
            x = solve(prices, i + 1,1,fee,dp) -prices[i]; // buy then money in purse reduce and now in sell 
            y = solve(prices, i + 1,2,fee,dp); // not buy then no money reduce and in buy phase 
        } else { // can sell only
            x = solve(prices, i + 1, 2,fee,dp) + prices[i]-fee; // sell then fee deduct and then money inc
            y = solve(prices, i + 1,1,fee,dp); // no sell then no money inc,fee
        }
        dp[i][k] = max(x, y);
        return dp[i][k];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1)); 
       return  solve(prices, 0, 2,fee, dp); // y maximum hi return kr rha h 
        // here we are passing purse value and no of transection left total buy and sell
        // if we are in buy situation then k=2 , else k=1 
    }
};