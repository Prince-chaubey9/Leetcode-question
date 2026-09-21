class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        string ans = "";
        string x = "";
        string y = "";
        for (int i = n - 1; i >= 0; i--) {
            string_view x(s.data(), i); // string_view ak inbult class h jo string k kisi part k view deti h bina copy creat kiy with time of o(1) and space also 
            string_view y(s.data() + n - i, i);
            if (x == y) {
                ans = x;
                return ans;
            }
        }

        return ans;
    }
};