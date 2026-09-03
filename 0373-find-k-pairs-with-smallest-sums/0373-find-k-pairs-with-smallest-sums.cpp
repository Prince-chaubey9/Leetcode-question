class Solution {
public:
    typedef pair<int,vector<int>> pi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi> pq; // in a max heap push pair of sum and ele of that sum
        int i=0,j=0;
        int sum;
        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {

                int sum = nums1[i] + nums2[j];

                // If heap already has k pairs
                // and current sum is greater than
                // the largest sum in heap,
                // no need to continue this row.
                if (pq.size() == k && sum >= pq.top().first)
                    break;

                pq.push({sum, {nums1[i], nums2[j]}});

                if (pq.size() > k)
                    pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};