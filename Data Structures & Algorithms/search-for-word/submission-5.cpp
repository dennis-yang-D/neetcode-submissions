class Solution {
public:
    bool isExist = false;
    string curr = "";
    string word1;
    unordered_map<int, bool> visited;
    bool exist(vector<vector<char>>& board, string word) {
        word1 = word;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                //visited.clear();
                backtrack(board, i, j);
            }
        }
        return isExist;
    }

    void backtrack(vector<vector<char>>& board, int i, int j) {
        if(visited[i * 10 + j]) {
            return;
        }
        visited[i * 10 + j] = true;
        curr += board[i][j];
        if(curr == word1) {
            isExist = true;
            return;
        }
        if(curr.size() == word1.size()) {
            curr.pop_back();
            visited[i * 10 + j] = false;
            return;
        }

        if(i > 0) {
            backtrack(board, i - 1, j);
        }
        if(i < board.size() - 1) {
            backtrack(board, i + 1, j);
        }
        if (j > 0) {
            backtrack(board, i, j - 1);
        }
        if (j < board[0].size() - 1) {
            backtrack(board, i, j + 1);
        }

        curr.pop_back();
        visited[i * 10 + j] = false;
    }
};
