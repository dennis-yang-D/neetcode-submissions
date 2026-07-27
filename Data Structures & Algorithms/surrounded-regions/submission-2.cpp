class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // char B is visited but not turned into X

        stack<pair<int, int>> dfs;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O') {
                    dfs.push({i, j});

                    unordered_set<int> coords;
                    bool touch_edge = false;

                    while(!dfs.empty()) {
                        auto t = dfs.top();
                        dfs.pop();

                        if(t.first < 0 || t.first >= board.size() || t.second < 0 || t.second >= board[0].size()) {
                            continue;
                        }
                        if(board[t.first][t.second] != 'O') {
                            continue;
                        }
                        if(t.first == 0 || t.first == board.size()-1 || t.second == 0 || t.second == board[0].size()-1) {
                            touch_edge = true;
                        }
                        board[t.first][t.second] = 'B';
                        coords.insert(t.first * 1000 + t.second);

                        dfs.push({t.first-1, t.second});
                        dfs.push({t.first+1, t.second});
                        dfs.push({t.first, t.second-1});
                        dfs.push({t.first, t.second+1});
                    }

                    if(!touch_edge) {
                        for(int c : coords) {
                            int x = c / 1000;
                            int y = c % 1000;
                            board[x][y] = 'X';
                        }
                    }
                }
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
