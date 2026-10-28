class Solution {
public:
    int ans = 0;
    int solve(vector<int>& prices, int i, int transect,vector<vector<int>>& dp) {
        if (transect == 0 ||i >= prices.size()) { // all transectioned completed
            return 0;
        }
        if (dp[i][transect] != -1)
            return dp[i][transect];

        int x, y= INT_MIN;
        if (transect % 2 == 0) { // can buy only
            x = solve(prices, i + 1, transect - 1,dp) -prices[i]; // buy then money we have reduce and no of
                                                                  // transection reduce

            y = solve(prices, i + 1,transect,dp); // not buy then no money reduce and no of
                                                  // tranection also
        } else { // can sell only
            x = solve(prices, i + 1, transect - 1,dp) + prices[i]; // sell money we have inc and no of transection inc
            y = solve(prices, i + 1,transect,dp); // no sell then no money inc
        }
        dp[i][transect] = max(x, y);
        return dp[i][transect];
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int k=4;
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
       return  solve(prices, 0, k, dp); // y maximum hi return kr rha h 
        // here we are passing purse value and no of transection left total buy and sell
        // here we can buy 2 time and sell 2 times so total 4 transect
    }
};