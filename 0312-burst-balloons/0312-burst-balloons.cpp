// recursive method 
// top down approach usin DP and recursion 
// isme i to j tk array mila ise partition kiya 
// kth position pr 
// and mana k kk left side wala and right side array solve hone pr k last ele bachega to 
// k dono side k ans ko sum and then k ko bhi uska adjacent ele se multiply kr add kiya 
class Solution {
public:
    int solve(vector<int> &nums, int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans= INT_MIN;
        for(int k=i;k<=j;k++){
            int x= solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j+1];
            ans= max(ans,x);
        }
        return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,1,n-2,dp);
    }
};