class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;  // kitne ele hatane pr non overlaping ban jayeg a
        sort(points.begin(), points.end());
        int last = points[0][1]; // first interval ko iclude kr k uska endtime
        for (int i = 1; i<points.size(); i++) {
            if (points[i][0] <=last) { // agr curent vector k start time previous includ k end
                        // time se km h to ak ko hatana hoga
                count++;
                last = min(last, points[i][1]); // jiska end time km ho us
                                                   // interval ko rakh lenge

            } else {
                last = points[i][1]; // interval ko include kai aur uska end time last ko dia
            }
        }
        int ans= points.size()-count;
        return ans;
    }
};

// kitne interval ko hatane pr ak bhi inter overlaping m nhi rhega vo pta kia nono overlapning m kitne ele honge wahi ans h 