class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        for (int i = 0; i < arr.size(); i++) { // freq kk sath map kia 
            mp[arr[i]]++;
        }
        for (auto x : mp) {
            pq.push(x.second); // frq ko heap m push kia
        }
        int count = 0;
        int n = arr.size(); // n is no ele in array 
        while (n > arr.size() / 2) { // jb tk no ele uski size/2 se zyada ho
            n -= pq.top(); // vo ele jnki freq jyada ho unhe nikalo 
            pq.pop();
            count++;
        }
        return count;
    }
};