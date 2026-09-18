// isme no of sub array count karenge jisme max k unique ele ho and mx k-1 wala bhi
// un dono k difference hi no of sub array have exact k ele hoga 
class Solution {
public:
    int atmost(vector<int>& nums, int k){
        if(k==0) return 0;
        int s=0; // starting indx to travel jaha se subarray suru hoga 
        int e=0;// last indx of sub array 
        int count=0;// count 
        unordered_map<int,int>mp; // map ele with its freq
        while(e<nums.size()){
           if(mp.size()<k){ // agr size<k h to 
            mp[nums[e]]++;// nums ki freq inc kro
            count+=(e-s+1); // nums[e] e indx se s tk jitne ele h sab k sath ak subarray creat krega and ak vo khud so count+=(e-s+1)
            e++; // e ko inc kia 
           }else if(mp.size()==k && mp.find(nums[e])!=mp.end()){ // agr size k h to 
             mp[nums[e]]++; // aur nums[e] mp m h to same as above 
            count+=(e-s+1);
            e++;
           }else{ // nhi to s ko inc kro means sub array k strt change 
            mp[nums[s]]--; // freq reduce 
            if(mp[nums[s]]==0) mp.erase(nums[s]); // freq 0 to remove 
            s++;
           }
        }
        return count; // count return 
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (atmost(nums,k)-atmost(nums,k-1)); // k or k-1 k liy count 
    }
};