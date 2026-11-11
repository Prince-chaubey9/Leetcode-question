// use backtracking and recursion 
// isme sabhi ele ko select kiay one by one
// kisi indx pr koi ele select kia to next k liy pass kr diya 
class Solution {
public:
    vector<vector<int>> ans;
    void helper(int n, int num, int k, vector<int>& temp) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = num; i <= n; i++) {
            temp.push_back(i);
            helper(n, i+1, k, temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        helper(n, 1, k, temp);
        return ans;
    }
};