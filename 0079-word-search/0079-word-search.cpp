class Solution {
public:
    bool ans = false;
    string w;
    void helper(vector<vector<char>>& board, int ro, int clm, int i) {
        if (i == w.size()) {
            ans = true;
            return;
        }
        if (ans) { // agr ans mil gye to return , no further check 
            return;
        }

        if (ro < 0 || clm < 0 || ro >= board.size() || clm >= board[0].size() ||
            board[ro][clm] != w[i]) { // agr current indx ele trgt ele nhi h to return 
            return;
        }
        board[ro][clm] = '.'; // current indx ko visited mark kiya 
        helper(board, ro, clm + 1, i + 1); // all possible side ko visit kiya 
        helper(board, ro + 1, clm, i + 1);
        helper(board, ro, clm - 1, i + 1);
        helper(board, ro - 1, clm, i + 1);
        board[ro][clm] = w[i]; // use unmark kiya for backtrackung
        return; // return 
    }
    bool exist(vector<vector<char>>& board, string word) {
        w = word;
        for (int i = 0; i < board.size(); i++) { // grid k sabhi indx k liy check kiya 
            for (int j = 0; j < board[0].size(); j++) { // trgt word kisi bhi indx se strt ho skta h 
                helper(board, i, j, 0);
                if (ans) { // agr ans mil gya to return , no furthe check 
                    return ans;
                }
            }
        }

        return ans;
    }
};