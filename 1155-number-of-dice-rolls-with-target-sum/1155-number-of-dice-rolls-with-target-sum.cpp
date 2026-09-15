class Solution {
public:

    int helper(int n, int k, int t, vector<vector<int>>& dp) {
        if (t == 0 && n == 0) // throw krne k liy reman dice and target dono 0 ho gye means target ban gya 
            return 1;
        if (n == 0|| t==0) // agr target y dice koi ak khtm ho gya to 0
            return 0;
        if (dp[n][t] != -1) { // agr kisi trget k liy pahle hi compute kr chuke h to dobara nhi krn a
            return dp[n][t];
        }
        int mod=1000000007; // modulas
        int ans = 0;
        for (int j = 1; j <= k; j++) {
            if (t - j < 0) // agr -ve ho rh ato compute nhi krn a
                continue;
            ans = (ans%mod+ helper(n - 1, k, t - j, dp)%mod)%mod; 
            // ak dice throw kia to remain = n-1 and us pr j value aya to taget= target-j
        }

        return dp[n][t] = ans; // kisi trget k liy update kia and return kia 
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
        helper(n, k, target, dp);
        return dp[n][target];
    }
};