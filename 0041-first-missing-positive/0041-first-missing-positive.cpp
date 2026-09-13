class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0) s.insert(nums[i]);
        }
        int i=1;
        while(true){
            if(s.size()==0) return i;
            if(s.find(i)==s.end()){
                return i;
            }else{
                s.erase(i);
            }
            i++;
        }
    }
};