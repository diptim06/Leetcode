class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowSeen[9][9] = {false};
        bool colSeen[9][9] = {false};
        bool boxSeen[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int num = board[r][c] - '1'; 
                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rowSeen[r][num] or colSeen[c][num] or boxSeen[boxIndex][num]) {
                    return false;
                }

                rowSeen[r][num] = true;
                colSeen[c][num] = true;
                boxSeen[boxIndex][num] = true;
            }
        }

        return true;
    }
};