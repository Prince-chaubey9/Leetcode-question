class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> x;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                st.push(i);
                i++;
            } else if (s[i] == '*') {
                x.push(i);
                i++;
            } else {
                if (st.size() > 0) {
                    st.pop();
                    i++;
                } else if (st.size() == 0 && x.size() > 0) {
                    x.pop();
                    i++;
                } else {
                    return false;
                }
            }
        }
        if (st.size() > 0) {
            if (st.size() > x.size())
                return false;
            while (st.size() > 0) {
                if (x.top() > st.top()) {
                    x.pop();
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};