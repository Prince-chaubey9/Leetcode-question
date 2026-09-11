class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort kia 
        int ans = 0;
        int i=0;
       while(i<nums.size()) { // even index ele ko sum kia 
       
            ans += nums[i];
            i+=2;
        }
        return ans;
    }
};