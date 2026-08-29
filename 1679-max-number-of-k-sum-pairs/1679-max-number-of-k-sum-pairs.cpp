class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // first int is ele and second is its freq
        int count=0;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto x:mp){
            int ele=x.first; // map se ak ele liya jiske pairs check krne h 
            int rem= k-ele; // remaining value jo map m agr h to ele and that value will pair 

            if(rem==ele){ // agr k==ele h to 
                count+=(mp[ele]/2); // jitni bar ele hoga uske adhe pars honge, odd hone pr 
               // mp.erase(ele);
                continue;
            }
            if(mp.find(rem)!=mp.end()){
                if(mp[ele]<=0 || mp[rem]<=0) continue; // agr freq -ve h to pair nhi ban sakta means sabhi occurance remove ho chuki h 
                int pair= min(mp[ele],mp[rem]); // kitne pair ban sakte h 
                count+= pair; // dono m jiski freq km utne hi pair banenge
                mp[ele]-=pair;// ele ko freq km kro kyukivo pair bana chuka h
                mp[rem]-=pair; // same with rem 
            }
        }
        return count;
    }
};