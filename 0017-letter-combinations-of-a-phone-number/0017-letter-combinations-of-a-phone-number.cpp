// recursion and backtracking 

class Solution {
public:
    unordered_map<char, vector<char>> mp;
    vector<string> ans;
    void helper(string digit, int i, string& temp) {
        if (i == digit.size()) { // digit k sabhi ele visit ho huke h 
            ans.push_back(temp); // ans m push 
            return;
        }
        for (auto x : mp[digit[i]]) { // current digti pr jitne char map un sab ko one one by one selec t kiya  
            temp.push_back(x); // unhe temp m push kiya 
            helper(digit, i + 1, temp); // temp ko digit k next ele k liy pass kiya 
            temp.pop_back(); // temp se pop kiya so temp same rahe 
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        mp['2'] = {'a', 'b', 'c'}; // sabhi ele ko map kiya 
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        string temp = "";
        helper(digits, 0, temp);
        return ans;
    }
};