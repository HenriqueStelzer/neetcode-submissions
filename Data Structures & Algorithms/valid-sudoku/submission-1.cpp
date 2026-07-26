class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bool, 9> a{};
        // Rows
        for (int i = 0; i < 9; i++) {
            a = array<bool, 9>{};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (a[board[i][j] - '1']) return false;
                a[board[i][j] - '1'] = true;
            }
        } 
        // Cols
        for (int i = 0; i < 9; i++) {
            a = array<bool, 9>{};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (a[board[j][i] - '1']) return false;
                a[board[j][i] - '1'] = true;
            }
        }
        // Squares
        for (int k = 0; k < 9; k++) {
            a = array<bool, 9>{};
            for (int i = k/3 * 3; i < (k/3 + 1) * 3; i++) {
                for (int j = (k%3) * 3; j < (k%3 + 1) * 3; j++) {
                    if (board[i][j] == '.') continue;
                    if (a[board[i][j] - '1']) return false;
                    a[board[i][j] - '1'] = true;
                }
            }
        }
        return true;
    }
};
