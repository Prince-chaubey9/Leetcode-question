class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp; // first int is arr[i] second is its freq
        unordered_set<int> s; // store freq of ele
        for(int i=0; i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto x:mp){
            int freq= x.second; // ele ki freq 
            if(s.find(freq)!=s.end()) return false; // agr freq pahle se h means same freq kisi aur ele k bhi h 

            s.insert(freq); // agr pahle se nhi h to insert kr do 
        }
        return true;
    }
};