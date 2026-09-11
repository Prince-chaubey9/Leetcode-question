class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1= INT_MAX;
        int min2=INT_MAX; // do min ele ko mark kr lo fir third le unse bada ho 
        for (auto n : nums) {
            if (n <= min1) // agr n min1 se chota h to min1=n and ab agla compare isi se hoga 
                min1 = n;
            else if (n <= min2) // agr min1 se nhi h lekin min2 h to second min2=n 
                min2 = n;
            else  // agr dono se hi chota nhi h to third big ele mil gya return true 
                return true;
        }
        return false;
    }
};