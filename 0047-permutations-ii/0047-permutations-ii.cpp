// recursion + backtracking 
class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void helper(vector<int>& nums, int i) {
        if (i == nums.size()) {
            st.insert(nums);
            return;
        }
        int idx= i;
        while(idx<nums.size()-1&&nums[idx]==nums[idx+1]) idx++; // duplicate ele ko apas m swap n krna pade 
        while(idx<nums.size()) {
            swap(nums[idx], nums[i]); // ith indx pr place krne k liy ith indx se age k sabhi ele ko one by one chance 
            helper(nums, i + 1); // now i+1th indx pr palcement 
            swap(nums[idx], nums[i]); // uske bad nums o exact same kiya jisase next ele sahi number se swap ho 
            idx++;
            while(idx<nums.size()-1&&nums[idx]==nums[idx+1]) idx++;
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums, 0);
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};