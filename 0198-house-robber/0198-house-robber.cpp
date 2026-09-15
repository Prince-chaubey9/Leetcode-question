// tabulation method 
// isme last house se check kia rob kia y nhi 
// nums[i] ko rob krne y n krne pr jo max hoga wahi 
// DP lecture 2 first or second question 

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n= nums.size();
        nums[n-2]= max(nums[n-2],nums[n-1]);
        for(int i=n-3; i>=0;i--){
            nums[i]= max(nums[i]+nums[i+2],nums[i+1]);
        }
        return nums[0];
    }
};