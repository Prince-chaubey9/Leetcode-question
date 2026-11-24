class Solution {
public:
    vector<string> ans; // ans 
    unordered_set<string> st; // string set to store word 
    void helper(string& s, string& temp, int i) {
        if (i == s.size()) { // if all words check ed and s string end 
            ans.push_back(temp);
            return;
        }
        string t; // temporary string for a word 
        int oldsize = temp.size(); // old string size so can remove added t string for backtracking
        for (int j = i; j < s.size(); j++) {
            t += s[j]; // make string after index i to put in temp 

            if (st.find(t) != st.end()) { // is t is in st then add it in temp 
                if (temp.empty()) temp += t; // is t is empty then no space 
                else temp += " " + t; // with space 
                helper(s, temp, j + 1); // fun call
                temp.erase(oldsize); // rempve added string 
            }
        }
        return;  // return 
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        string temp; // temp string to insert in ans 
        for (int i = 0; i < word.size(); i++) { // put all words in a set so can easily
            st.insert(word[i]);
        }
        helper(s, temp, 0);
        return ans;
    }
};