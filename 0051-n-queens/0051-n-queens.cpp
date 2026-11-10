// recursion and backtracking 
class Solution {
public:
    vector<vector<string>> ans; // final vector which store ans;
    bool can_place(int row, int clm, int n, vector<string>& grid) { // current grid m travel kr check kro row, clm pr place kr skte h y nhi
        for (int i = row; i >= 0; i--) { // current clm m kisi row m queen place or not
            if (grid[i][clm] == 'Q')
                return false; // if yes the return false
        }
        int i = row, j = clm;
        while (i >= 0 && j >= 0) { // diagonal left side chek and upper
            if (grid[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row, j = clm;
        while (i >= 0 && j < n) { // diagonal right side chek and upper
            if (grid[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(int row, int n, vector<string>& grid) {
        if (row == n) { // all rows ko check kr chuke h
            ans.push_back(
                grid); // grid jo vector of string h isme queen place done
            return;
        }
        for (int clm = 0; clm < n; clm++) {
            if (can_place(
                    row, clm, n,
                    grid)) { // agr curent row,clm pr queen place kr skte h
                grid[row][clm] = 'Q';     // clm indx pr queen place ki
                helper(row + 1, n, grid); // next row m move kia
                grid[row][clm] =
                    '.'; // place queen ko unplace kia and next iteration
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string temp(n, '.');
        vector<string> grid(n, temp); // ak board create kiay jisme kahi bhi queen place nhi h 
        helper(0, n, grid); // pass current row and total number of row
        return ans;
    }
};