class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> ele; // store ele , freq
        map<int,vector<char>> freq; // store freq, ele
        string ans="";
        for(auto x: s){
            ele[x]++;
        }
        for(auto x: ele){
            int fr= x.second;
            char el= x.first;
            freq[fr].push_back(el);
        }
        for(auto x: freq){
            int n= x.first;
            int c= x.second.size();
            for(auto ch : x.second){
                for(int i=0; i<n;i++) ans+=ch;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};