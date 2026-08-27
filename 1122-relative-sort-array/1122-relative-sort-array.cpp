class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end()); // arr1 ko sort kia 
        vector<int>ans;
        unordered_map<int,int> mp; // first int is arr1[i] and second its freq
        unordered_set<int> st; // set m arr2 k ele bhare 
        for(int i=0; i<arr2.size();i++){
            st.insert(arr2[i]);
        }
        for(int i=0; i<arr1.size();i++){
            mp[arr1[i]]++;// map ith ele with its frq 
        }

        for(int i=0; i<arr2.size();i++){ // arr2 k ele map m jitni freq m h utni time ans m push 
                while(mp[arr2[i]]>0){
                    ans.push_back(arr2[i]);
                    mp[arr2[i]]--;
                }
        }
        for(int i=0; i<arr1.size();i++){ // kux ele arr2 m nhi h unhe set se check kia aur ans m push
            if(st.find(arr1[i])==st.end()) ans.push_back(arr1[i]);
        }
        return ans;
    }
};