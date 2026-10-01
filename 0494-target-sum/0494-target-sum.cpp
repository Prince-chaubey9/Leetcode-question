// use DP tabulation method
// top to down
// use knapsack
// let s1 and s2 two subset h s1 m vo ele jinhe +ve sign diya and s2 m vo ele
// jinhe -ve sign diya now we just need to find no of ways to get s1-s2 = target
// and we know s1+s2 = total sum
// usnig this get s1 = (target+total)/2
// just find no of ways to find s1 in this nnumse ele
// just like subset sum problem
// isme vo subset k no find krna h jinka sum s1 h

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        if ((total + target) % 2 != 0 || total < abs(target)) {
            return 0; // impossible to form target
        }
        int sum = (total + target) / 2; // kisi subset k sum jisme +ve ele h
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0)); // 0 se initialze kia to 0th row ko
                                                                 // initialize nhi krna pada
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // first colum ko 1 se initialze kia bcz sum 0 banane
                          // k 1 hi way h
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i - 1] <=j) { // jis ele ko cjose krne y nhi krna decide kr rahe h vo
                         // jo sum chaiy "j"usase km h y nhi
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    // y to include kia y nhi kiya
                }else {
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
// this is dp method with out recursion
