// backtracking

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& can, int tar, int i, vector<int>& temp) {
        if (tar == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == can.size()) {
            return;
        }
        if (can[i] <= tar) {
            temp.push_back(can[i]);
            solve(can, tar - can[i], i + 1, temp);
            temp.pop_back();
        }
        int j = i + 1; // temp variable for duplicate ele skip
        while (j < can.size() && can[j] == can[j - 1])
            j++;
        solve(can, tar, j, temp);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        vector<int> temp;
        sort(can.begin(), can.end());
        solve(can, tar, 0, temp);
        return ans;
    }
};