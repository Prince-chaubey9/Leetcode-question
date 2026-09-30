class Solution {
public:
    int count = 0;
    void helper(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size() && sum == target) {
            count++;
            return;
        }
        if (i >= nums.size())
            return;
        helper(nums, i + 1, sum + nums[i], target); // agr +ve sign liya to
        helper(nums, i + 1, sum - nums[i], target); // agr -ve sign lya to
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        helper(nums, 0, 0, target);
        return count;
    }
};
// isme target -ve  ho j rha h to dp based indexing not possible bcz -ve indx nhi hote 