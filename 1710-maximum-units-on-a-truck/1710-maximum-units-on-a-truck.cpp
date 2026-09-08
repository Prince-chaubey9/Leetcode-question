class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int trucksize) {
        int ans = 0;
        vector<vector<int>> v;
        for (int i = 0; i < box.size(); i++) {
            vector<int> temp = {box[i][1], box[i][0]}; // 2D vector contain unit per box and no of boxes
            v.push_back(temp);
        }
        sort(v.begin(), v.end()); // sort to get min unit per box
        reverse(v.begin(), v.end()); // reverse to get mx unit per box 
        int i = 0;
        while (trucksize > 0) { // place boxes to truck while there is space
            if (v[i][1] <= trucksize) {
                ans += (v[i][0] * v[i][1]); // unit per box *no of boxes
                trucksize -= v[i][1];// capacity remains in truck
                i++;
            } else {
                ans += (v[i][0] * trucksize); // jitni space remaining h utne hi box rakh do 
                break;
            }
            if(i==v.size()) break;// total no available box se jyada sapce hui to 
        }
        return ans;
    }
};