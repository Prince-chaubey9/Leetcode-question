// bottom up approach
// isme indx i,j kitni size k sub square  k part hoga y uske uper , bagal ,
// digonal k min +1 se decide hoga

class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && i > 0 && j > 0) { // agr value 1 h and i>0 , j>0 h tabhi vo 1 se bada square bana skta h 
                    mat[i][j] = 1 + min({mat[i - 1][j], mat[i][j - 1],mat[i - 1][j - 1]});
                }
                sum += mat[i][j];
            }
        }
        return sum;
    }
};