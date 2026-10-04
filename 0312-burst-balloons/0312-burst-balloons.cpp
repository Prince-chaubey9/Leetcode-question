// recursive method
// tabulation method using dp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >=1; i--) {
            for (int j = 1; j <= n; j++) {
                if(i>j) continue;
                int ans = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int x = dp[i][k - 1] + dp[k + 1][j] +
                            nums[i - 1] * nums[k] * nums[j + 1];
                    ans = max(ans, x);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};