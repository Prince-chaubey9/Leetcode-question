class Solution {
public:
    typedef pair<int, int> p;
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        int ans = 0;
        vector<p> temp;             // ele and index
        unordered_map<int, int> mp; // kis indx k ele ko kitni rating mili h
        for (int i = 0; i < ratings.size(); i++) { // ele ko unke index k sath pair kia 
            temp.push_back({ratings[i], i});
        }
        sort(temp.begin(), temp.end()); // temp ko sort kia 
        for (int i = 0; i < temp.size(); i++) {
            int ele = temp[i].first; // ith ele k value and uska index liya 
            int indx = temp[i].second;
            if (indx == 0) { // agr indx 0 h to usee 1 indx se compare kia 
                if (ratings[0] > ratings[1]) {
                    mp[0] = mp[1] + 1; // agr 0th indx ele 1 indx ele se bada h to 1 indx ele ko jitni choclate mili +1 ise 
                } else {
                    mp[0] = 1; // nhi to sirf 1
                }
            } else if (indx == ratings.size() - 1) { // same with last indx 
                if (ratings[indx] > ratings[indx - 1]) {
                    mp[indx] = mp[indx - 1] + 1;
                } else {
                    mp[indx] = 1;
                }
            } else if (ratings[indx] > ratings[indx - 1] &&ratings[indx] >ratings[indx + 1]) { // left and right dono  se bada h to
               mp[indx]= max(mp[indx-1],mp[indx+1])+1; // jis dono m jise jyada mili +1

            } else if (ratings[indx] > ratings[indx - 1]) { // agr sirf indx -1 se bada h to 
                mp[indx] = mp[indx - 1] + 1;
            } else if (ratings[indx] > ratings[indx + 1]) { // agr sirf indx+1 se bada h to
                mp[indx] = mp[indx + 1] + 1;
            } else { // agr kis se bada nhi h to sirf 1 
                mp[indx] = 1;
            }
        }
        for (auto x : mp) { // kis indx ko kitni choclate mili count kro and ans
            int candi = x.second;
            ans += candi;
        }
        return ans;
    }
};