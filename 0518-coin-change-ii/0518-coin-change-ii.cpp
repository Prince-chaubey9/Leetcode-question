// recursive method 
// use DP method and store way in 2D array 

class Solution {
public:int count=0;
    int way(int amount, vector<int> & coins, int idx, int sum, vector<vector<int>>&dp){
        if(sum==amount){
            return 1 ;
        }
        if(idx==coins.size() || sum>amount) return 0;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
       int x= way(amount,coins,idx,sum+coins[idx],dp);// include kiya to multi times include kr skte h 
       int y= way(amount,coins,idx+1,sum,dp); // include nhi kiya to ab next indx coin k liy check kro
        return dp[idx][sum]=x+y ;
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
       return way(amount,coins,0,0,dp);
    }
};

// this is unbound knapsack problem where can select an ele multi times 