// use min heap
// isme first colum k sabhi ele ko  min heap m push kiay aur unka max aur min
// find kia
// \jo current range k first and second ele honge  annd usk range note ki
// uske bad jo ele h min h us row m ek colum age badhe aur next ele ko min heap
// m push kiya , max ko update kiya , arangefind ki  , min range kon update kiya

class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mx = INT_MIN; // an variable store max value of range
        priority_queue<p, vector<p>, greater<p>>hp; // store one ele from every row
        for (int i = 0; i < nums.size();
             i++) { // here we push first ele of every row
            hp.push({nums[i][0], {i, 0}}); // store ele , its row and colum
            mx = max(mx, nums[i][0]);
        }
        int mn = hp.top().first;         // min or first ele of range
        int range = mx - mn;             // range of first column
        int clm = 0;                     // colum by which we travel whole array
        int row = hp.top().second.first; // row of current min ele of heap
        int b = mx;                      // temporary second ele of range array
        int a = mn;                      // temp first ele of range array
        while (!hp.empty()) {
            row = hp.top().second.first; // current ele row
            clm = hp.top().second.second;// current ele clm
            a = hp.top().first; // a, b are the ele of current range
            hp.pop(); // use baha kiya 
            int x = b - a;      // current range
            // mx and mn are the ele of updated range
            if (x < range) {
                range = x; // update range
                mx = b;    // update ele of range
                mn = a;
            }
            if(clm+1<nums[row].size()){ // agr clm apni row m out of range chala jay to 
                hp.push({nums[row][clm+1],{row,clm+1}});
                b= max(b,nums[row][clm+1]);
            }else {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(mn);
        ans.push_back(mx);
        return ans;
    }
};