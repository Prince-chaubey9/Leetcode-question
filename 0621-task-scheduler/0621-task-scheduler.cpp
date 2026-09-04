class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();
        unordered_map<char, int> mp; // char , freq
        unordered_map<int, int> st;  // kis frq k kitne ele h
        priority_queue<pair<int, int>>pq; // mx heap jisase mx fre and uus frq k kitn ele h
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        for (auto x : mp) {
            st[x.second]++;
        }
        for (auto x : st) {
            pq.push({x.first, x.second});
        }
        int c = pq.top().first;  // no of cycle be made
        int f = pq.top().second; // how many ele has max freq
        int count = 0;
        if (n >= mp.size()) {
            count = (c - 1) * (n + 1) + f; // (c - 1) * (n + 1)== no of ele filled in c-1 cycles
        } else {
            count = (c - 1) * (n + 1) + f;
            if(tasks.size()> count){ // agr windows m sabhi ele bharne k bad bhi bachte h to 
                count+= (tasks.size()- count);
            }
        }
        return count;
    }
};