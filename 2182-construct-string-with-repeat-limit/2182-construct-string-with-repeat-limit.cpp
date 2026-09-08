class Solution {
public:
    typedef pair<char, int> p;
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        unordered_map<char, int> mp; // map character to freq
        priority_queue<p> pq;        // store character and give mx ele
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (auto x : mp) {
            pq.push(x);
        }
        while (pq.size() > 0) {
            p large = pq.top(); // first largest ele ko pick kia
            int n = min(repeatLimit, large.second); // no of char jo add krne h 
            ans.append(n, large.first); // add kiy
            pq.pop(); // first large char ko pop kia 

            if (large.second - n > 0) { // check add krne k bad bhi remaining h 
                if (pq.size() != 0) { // second lrge ele h add krnek liy 
                    p z = pq.top(); // agr h to pick kia 
                    ans += z.first; // ak bar add kia 
                    pq.pop(); // pop kia 

                    if (z.second - 1 > 0) { // second large add krne bad frq remain h to
                        pq.push({z.first, z.second - 1}); // freq 1 se dec kr k push kia 
                    }
                }else{ // agr second large nhi to break kia bcz next loop m bhi same ele hi add ho jayega 
                    break;
                }
                pq.push({large.first, large.second - n}); // first large char ko push kia freq dec kr k
            }
        }
        return ans;
    }
};