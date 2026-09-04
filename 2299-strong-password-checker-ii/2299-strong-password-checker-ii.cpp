class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if (s.size() < 8)
            return false;
        bool u = false, l = false, n = false, sp = false;
        if (65 <= s[0] && s[0] <= 90)
            u = true;
        else if (97 <= s[0] &&s[0] <= 122)
            l = true;
        else if (48 <= s[0] && s[0] <= 57)
            n = true;
        else if ((33 <= s[0] && s[0] <= 64)||(91<=s[0]&& s[0]<=96)||(123<=s[0] && s[0]<=126))
            sp = true;
        int i = 1;
        while (i < s.size()) {
            if (s[i] == s[i - 1])
                return false;

            if (65 <= s[i] && s[i] <= 90)
                u = true;
            else if (97 <= s[i] && s[i] <= 122)
                l = true;
            else if (48 <= s[i]&& s[i] <= 57)
                n = true;
            else if ((33 <= s[i] && s[i] <= 64)||(91<=s[i]&& s[i]<=96)||(123<=s[i] && s[i]<=126))
                sp = true;
            i++;
        }
        if (u && l && n && sp)
            return true;

        return false;
    }
};