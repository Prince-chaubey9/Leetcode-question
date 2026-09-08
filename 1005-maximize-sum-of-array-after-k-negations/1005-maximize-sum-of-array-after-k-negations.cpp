class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum =0;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]); // sabhi le ko heap m push kia 
            sum+=nums[i]; // sum find kia 

        }
        while(k>0){
            int ele= pq.top(); // heap k top ele ko pick kia 
            pq.pop(); // use pop kia 
            sum-=ele; // sum m se reduce kia 
            ele*=(-1); // -1 se multi ply kia 
            pq.push(ele); // push kia 
            sum+=ele; // sum m add kia 
            k--; // ko reduce kia 
        }
        return sum;
    }
};