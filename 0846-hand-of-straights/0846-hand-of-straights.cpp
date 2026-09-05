class Solution {
public:
    void helper(vector<int>& v, int ele, int size) {
        while (v.size() < size) {
            ele++;
            v.push_back(ele);
        }
        return;
    }
    bool isNStraightHand(vector<int>& hand, int group) {
        if (hand.size() % group != 0)
            return false;
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap used

        for (int i = 0; i < hand.size(); i++) { // sabhi ele ko map kiya freq k sath
            mp[hand[i]]++;
        }
        for (auto x : mp) { // min heap m push kia
            pq.push(x.first);
        }

        while (pq.size() > 0) { // jb tk heap m ele h 
            vector<int> v; // vector banaya 
            if (mp.find(pq.top()) == mp.end()) { // agr heap k top map m nhi h to pop kiya aur loop dobara chalaya 
                pq.pop();
                continue;
            }
            if (pq.size() == 0) // agr pop krte hi pq empty ho gya to
                break;
            v.push_back(pq.top()); // pq.top ko v . push kia 

// group pq.top se suru hoga aur consecutive ele chahiy to v m consecutive ele push kiy helper fun se 
            helper(v, pq.top(), group); // fun call
            for (auto ele : v) { // v jo group banega check kia sabhi ele map m h meanshand array m h y nhi 
                if (mp.find(ele) != mp.end()) { // agr h to freq kh kro
                    mp[ele]--;
                    if (mp[ele] == 0)
                        mp.erase(ele);
                } else { // agr koi ele nhi h to grou nhi bn sakta 
                    return false;
                }
            }
        }
        return true; // all condition satisfied 
    }
};