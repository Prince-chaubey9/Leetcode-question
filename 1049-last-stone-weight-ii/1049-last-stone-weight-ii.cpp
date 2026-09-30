// using knapsack method of DP 
// vo sabhi sum find kiy jo nums array k sabhi subset se milte 
// s1, s2 dono subset k sum h aur s1-s2 ko min krna h 
// s1 jo sabhi sum m first half sum honge 
// and s1-s2 ko sbhi ele sum -2*s1[i] likh sakte h ise min kia to ans mil gya 

class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int i=0; i<n;i++){
            sum+=nums[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1)); // 2D vector jo sare sum store kre 

        for(int i=0; i<=n;i++){
            for(int j=0; j<=sum;j++){
                if(i==0 && j==0) {
                    dp[0][0]= true;
                    continue;
                }
                if(i==0){
                    dp[i][j]= false;
                    continue;
                }
                if(j==0){
                    dp[i][j]= true;
                    continue;
                }
                if(nums[i-1]<=j){
                    dp[i][j]= dp[i-1][j]|| dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        vector<int> s1; //sabhi sum m se half sum ko s1 m store kia 
        for(int i=0; i<=sum/2; i++){
            if(dp[n][i]==true) s1.push_back(i);
        }
        int ans=INT_MAX;
        for(int i=0; i<s1.size();i++){ // min find kia
            ans= min(ans,sum-2*s1[i]);
        }
        return ans;
    }
};