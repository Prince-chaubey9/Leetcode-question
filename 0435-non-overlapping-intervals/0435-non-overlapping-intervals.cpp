class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int last = intervals[0][1]; // first interval ko iclude kr k uska endtime
        for (int i = 1; i<intervals.size(); i++) {
            if (intervals[i][0] <last) { // agr curent vector k start time previous includ k end
                        // time se km h to ak ko hatana hoga
                ans++;
                last = min(last, intervals[i][1]); // jiska end time km ho us
                                                   // interval ko rakh lenge

            } else {
                last = intervals[i][1];
            }
        }
        return ans;
    }
};

// agr koi do interval overlap kr rahe h to use include kia jisak end time km ho 