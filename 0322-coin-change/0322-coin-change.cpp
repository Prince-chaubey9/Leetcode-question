// DP METHOD 

class Solution {
public:
    int helper(vector<int>& coins, int amount,vector<int>& dp){
        if(amount==0)return 0;
        if(dp[amount]!=-1) return dp[amount]; // agr amount se 0 k liy min coin h to wahi retun kia 
        int result=INT_MAX;
        for(auto coin:coins){ // nhi to sab k liy check kia 
            if(coin<=amount){
                int way= helper(coins, amount-coin,dp);
                if(way!=INT_MAX) result= min(result,1+way); 
            }
        }
        dp[amount]=result;
        return result;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans= helper(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
// pura recursive method hi h bas jo values k liy recursion bar bar 0 tk check kr he the unhe dp vector m store kr liya to multi call bach gyi 