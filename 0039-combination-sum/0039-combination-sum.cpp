class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& can, int tar, int i, int sum, vector<int> temp) {
        if (sum == tar) {
            ans.push_back(temp);
            return;
        }
        if (sum > tar)
            return;
        if (i >= can.size()) {
            if (sum == tar)
                ans.push_back(temp);
            return;
        }
        solve(can, tar, i + 1, sum, temp);
        temp.push_back(can[i]);
        solve(can, tar, i, sum + can[i], temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<int> temp;
        solve(can, tar, 0, 0, temp);
        return ans;
    }
};