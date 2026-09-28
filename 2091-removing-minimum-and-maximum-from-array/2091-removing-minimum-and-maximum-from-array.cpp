class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                y = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                x = i;
            }
        }
        int n = nums.size();
        return min({min(x, y) + n - max(x, y)+1, max(x, y) + 1, n - min(x, y)});
    }
};