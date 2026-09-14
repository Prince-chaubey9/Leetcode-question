// DP use inspite of recursion 

class Solution {
public:
    int helper(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx == nums.size() - 1)
            return nums[idx];
        if (idx == nums.size() - 2)
            return max(nums[idx], nums[idx + 1]);
        if (dp[idx] != -1)
            return dp[idx];
        dp[idx] = max(nums[idx] + helper(nums, idx + 2, dp),helper(nums, idx + 1, dp));
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(105, -1);
        return helper(nums, 0, dp);
    }
};