class Solution {
public:
    unordered_set<int> st;
    void helper(vector<vector<int>>& rooms, int i) {
        st.insert(i); // jis room ko open kiya use visited mark kro 
        for (int j = 0; j < rooms[i].size(); j++) { // rooms[i][j]= next room aur subvector no h 
            if (st.find(rooms[i][j]) == st.end()) { // agr visit nhi kiya h to visit kro 
                helper(rooms, rooms[i][j]);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        helper(rooms, 0);
        for (int j = 1; j < rooms.size(); j++) {
            if (st.find(j) == st.end())
                return false;
        }
        return true;
    }
};