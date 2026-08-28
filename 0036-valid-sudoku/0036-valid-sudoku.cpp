class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> colum;
        unordered_map<int,unordered_set<char>> row;
        unordered_map<int,unordered_set<char>> box;


        for(int i=0; i<9;i++){ // i define colum number

            for(int j=0; j<9;j++){ // j define row number
                if(board[i][j]=='.') continue; // if ele is not digit

                if(row[i].find(board[i][j])!=row[i].end()) return false; // check row left to right
                else row[i].insert(board[i][j]);

                if(colum[j].find(board[i][j])!=colum[j].end()) return false;//check colum up to down
                else colum[j].insert(board[i][j]); //j th colum m ele insert 

                 int bxIdx = (i / 3) * 3 + (j / 3); // index of box kis index k box m check krna h 

                 if(box[bxIdx].find(board[i][j])!=box[bxIdx].end()) return false;
                 else box[bxIdx].insert(board[i][j]);



            }

        }


        return true;
    }
};