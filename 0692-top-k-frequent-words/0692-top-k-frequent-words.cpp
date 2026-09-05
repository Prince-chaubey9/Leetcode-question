class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<int> pq;              // use max heap of pair
        unordered_map<string, int> mp;         // string,freq
        unordered_map<int, vector<string>> fr; // kis freq pr kon kon se ele h map kia 

        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        for (auto ele : mp) {
            string s = ele.first;
            int freq = ele.second;
            fr[freq].push_back(s); // frq map m words ko push kia
        }
        for (auto ele : fr) {
            pq.push(ele.first); // freq ko heap m push kia
        }
        while (ans.size() < k) {
            vector<string> x = fr[pq.top()]; // mx fre wale ele k vector ko xm store kia 
            pq.pop(); // mx freq ko pop kia
            sort(x.begin(), x.end()); // x ko sort kia 
            for (int i = 0; i < x.size(); i++) { // x k sabhi ele ans m push kiy
                ans.push_back(x[i]);
                if (ans.size() >= k) // agr ans size>=k to break or return 
                    break;
            }
        }
        return ans;
    }
};