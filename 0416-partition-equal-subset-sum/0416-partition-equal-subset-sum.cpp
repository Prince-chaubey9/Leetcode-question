// y DP k iterative method h bina recursion k use kiy 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        sum = sum / 2; // for equal sum just find half of total sum , is it
                       // possible to make an subset with this sum
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) { 
                if (i == 0 && j == 0) { // for 0,0
                    dp[i][j] = true;
                    continue;
                }
                 if (i == 0) { // 0 ele k sath koi sum nhi bn skta 
                    dp[i][j] = false;
                    continue;
                }
                 if (j == 0) { // 0 sum to kitne bhi ele subset k liy bn sakta h 
                    dp[i][j] = true;
                    continue;
                }
                if(nums[i-1]<=j){ // agr nums k i-1 ele jo sum "j" chahiy usase km h to 
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    // y to use include kro y exclude kro 
                    // agr exclude kiya to check i-1 ele k sath "j" sum possible tha 
                    // agr include to i-1 ele k sath "j-nums[i-1]" sum possible tha 
                }else{
                    dp[i][j]= dp[i-1][j]; // agr num[i-1] jyada h to exclude wali condition
                }
            }
        }
        return dp[n][sum];// it defines 
        // n no. of ele wale array m koi subset h jiska sum "sum" k equal ho 
    }
};