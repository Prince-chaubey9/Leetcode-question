class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')') {
                if (st.size() != 0)
                    st.pop();
                else
                    ans++;
            }
        }
        ans += st.size();
        return ans;
    }
};