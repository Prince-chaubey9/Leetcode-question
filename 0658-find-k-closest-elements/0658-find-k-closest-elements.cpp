class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>>
            p; // isme first ele dist and second arr[i]

        for (auto ele : arr) {
            int dist = abs(x - ele); //ele ki x se distance find ki 
            p.push({dist, ele}); // dist or ele ko push kia 
            if (p.size() > k) // k min dist walw ele chahiye  
                p.pop(); // to k se zyadda hone pr unme se mx dist wale ele ko remove kia 
        }
        vector<int> ans;
        while (p.size() > 0) { // ans m push kia 
            int ele = p.top().second;
            ans.push_back(ele);
            p.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};