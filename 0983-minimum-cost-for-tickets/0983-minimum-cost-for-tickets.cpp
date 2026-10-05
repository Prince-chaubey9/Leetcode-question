// using dp method 

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if (i >= days.size()) // agr out of range h to 0
            return 0;
        if (dp[i] != -1) // if already checked
            return dp[i];
        int y = costs[1], z = costs[2]; // agr 7 day , 30 day pass liya to 
        int x = costs[0] + solve(days, costs, i + 1, dp); // agr 1 din pass liya to us din and next baki din ki cost
        for (int t = i; t < days.size(); t++) { // agr 7 day k pass liya to check days array m kb tk valid h 
            if (days[t] >= days[i] + 7) { // jis indx pr pass end usi age k array k ly check 
                y = costs[1] + solve(days, costs, t, dp);
                break;
            }
        }
        for (int t = i; t < days.size(); t++) { // same with 30 days pass
            if (days[t] >= days[i] + 30) {
                z = costs[2] + solve(days, costs, t, dp);
                break;
            }
        }
        return dp[i] = min({x, y, z}); // us indx k liy x,y,z k min hi ans h 
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n + 1, -1); // made dp array
        return solve(days, costs, 0, dp); // pass indx , dp, cost , days 
    }
};