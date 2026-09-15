class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=0; // store mx indx we can reach by jum 
        for(int i=0;i<nums.size();i++){
            if(i>mx) return false; // agr mx reach indx se age curent indx nikal gya means false
            mx=max(mx,i+nums[i]); // kis indx se mx kaha pahuch sakte h 
        }
        return true;
    }
};