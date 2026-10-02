// use tabulation method of dp to find longest commen subssequence 
// then jo ele str1,str2 m common nhi h unhe +lcs k ele ko add kr k jo 
// string bni bo sipersequence h 

class Solution {
public:
    string LCS(string x, string y) {
        int n = x.size(), m = y.size(); // dono string ki length
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));// 2d vector jaha kitne ele se mx kitni size ki lcs bn sakti h define 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i-1] == y[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // agr ele comon h to addd kiyaand move 
                } else { // agr nhi to ak bar x k liy -1 ,a nd ak bar y k liy -1 
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        string ans=""; // vo LCS string find ki ans m 
        // n no of row and m no of clm ko define kr rha h 
        while (m > 0 && n >0) {
            if (x[n-1] == y[m-1]) { // agr ele same h to add kro and move 
                ans += x[n-1];
                n--;
                m--;
            } else if (dp[n - 1][m] > dp[n][m - 1]) { // nhi to jiski value grtr h us indx pr move 
                                                     // usi string k ele ko add kia  
                ans+=x[n-1];  // yaha x k ele ko
                n--;
            }else{
                ans+=y[m-1]; // yaha y k ele ko 
                m--;
            }   // agr koi string end ho gyi to dusri string jitni remain h add kr do 
            if(m==0 && n!=0){
                while(n>0){ ans+=x[n-1];
                n--;}
            }else if(n==0&& m!=0){
                while(m>0){ ans+=y[m-1];
                m--;}
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = LCS(str1, str2);
       
        return lcs;
    }
};
