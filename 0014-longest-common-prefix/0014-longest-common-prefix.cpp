class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "",temp;
        string crnt = strs[0];
        for (auto x : strs) {
            int i = 0;
            temp = "";
            while (i < crnt.size() && i < x.size()) {
                if (crnt[i] == x[i]) {
                    temp += crnt[i];
                    i++;
                } else {
                    crnt = temp;
                    ans = crnt;
                    break;
                }
            }
            crnt = temp;
        }
        ans=temp;
        return ans;
    }
};