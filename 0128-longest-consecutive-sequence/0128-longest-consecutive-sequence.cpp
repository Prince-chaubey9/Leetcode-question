class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int mx = 0;
        int count=1;
        int i = 0;
        int j = 1;
        sort(nums.begin(), nums.end());
        int temp = nums[0]; // previous consecutive ele ko store kiy rahega 
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == temp)
                continue;
            if (nums[i] == temp + 1) {
                count++; // count last consecutive m kitne ele a chuke h 
                temp = nums[i];
            }else{
                mx=max(mx,count); // ele consecutive nhi h to max no store 
                count=1; // new consecutive find
                temp=nums[i];
            }
        }
        mx=max(count,mx);
        return mx;
    }
};