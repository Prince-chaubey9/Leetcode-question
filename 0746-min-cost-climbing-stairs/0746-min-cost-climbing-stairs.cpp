// tabulation method of DP

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
// ith indx pr pahuchne ki cost = cost[i]+ uske last two indx ppr pahuchne ki cost k min k barabar hogi