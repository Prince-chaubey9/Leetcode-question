class FindSumPairs {
public:
    vector<int>nums1;
    vector<int>nums2;
    unordered_map<int,int>mp; // class k public map creat kia 
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1; // dono vector ko initilize kia 
        this->nums2=nums2;
        for(int i=0;i<nums2.size();i++){ // nums k ele ko freq k sath map kia 
            mp[nums2[i]]++;
        }
        // vector ko initialize k time hi nums 2 ko map kr dia  
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--; //nums2 k indx val ko update kr rhe h to present time us index pr jo val h uski freq km ho jaygi 
        nums2[index] += val; // nums2 ki value update ki 
        mp[nums2[index]]++; // nyi val ki freq inc kri 

    }
    
    int count(int tot) {
        int x=0;
        for(int i=0;i<nums1.size();i++){// nums1 k har ak ele k liy pair check kia
            int rem = tot-nums1[i];
            if(mp.find(rem)!=mp.end()){
                x+=mp[rem];
            }
        }
        return x;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */