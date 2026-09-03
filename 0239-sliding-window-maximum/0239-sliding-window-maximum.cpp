class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n = nums.size();
        vector<int> ans;
        vector<int> ngi(n, n);
        stack<int> st;
        st.push(n-1);
        for (int i = n - 2; i >= 0; i--) { // next greater ele k index find
            while (st.size() > 0 && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            if (st.size() == 0) {
                st.push(i);
            } else {
                ngi[i] = st.top();
                st.push(i);
            }
        }
        int j = 0;
        int mx;
        for (int i = 0; i < n - k + 1; i++) {
            if (j < i || j >= i + k) {
                mx = nums[i];
                j = i;
            } else {
                mx = nums[j];
            }
            while (j < i + k) {
                mx = nums[j];
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};