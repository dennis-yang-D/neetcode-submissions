class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Step 1: rows
        for(int i = 0; i < 9; i++) {
            unordered_set<int> dup_map;
            for(int j = 0; j < 9; j++) {
                if(dup_map.contains(board[i][j])) {
                    return false;
                }
                if(board[i][j] == '.') {continue;}
                dup_map.insert(board[i][j]);
            }
        }

        // Step 2: cols
        for(int i = 0; i < 9; i++) {
            unordered_set<int> dup_map;
            for(int j = 0; j < 9; j++) {
                if(dup_map.contains(board[j][i])) {
                    return false;
                }
                if(board[j][i] == '.') {continue;}
                dup_map.insert(board[j][i]);
            }
        }

        // Step 3: squares
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                unordered_set<int> dup_map;
                for(int a = 3 * i; a < 3 * i + 3; a++) {
                    for(int b = 3 * j; b < 3 * j + 3; b++) {
                        if(dup_map.contains(board[a][b])) {
                            return false;
                        }
                        if(board[a][b] == '.') {continue;}
                        dup_map.insert(board[a][b]);
                    }
                }
            }
        }
        return true;
    }
};
