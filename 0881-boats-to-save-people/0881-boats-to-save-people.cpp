class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        int ans=0; 
        int n= nums.size();
        int i=0;
        int j= n-1;
        while(i<=j){
            if(nums[i]+nums[j]<=limit){ // agr available people m se min weight and max weight ka sum limit se km ho to dono ko pick kro 
                i++;
                j--;
                ans++;
            }else{
                j--;
                ans++;
            }
            if(i==j) {
                ans++;
                break;
            }
        }
        return ans;
    }
};