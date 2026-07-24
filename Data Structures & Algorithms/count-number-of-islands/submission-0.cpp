class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int, int>> dfs;
        // just edit grid for visited

        int islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs.push({i,j});
                    //cout << i << " " << j << endl;

                    while(!dfs.empty()) {
                        auto t = dfs.top();
                        dfs.pop();

                        if(grid[t.first][t.second] != '1') {continue;}
                        grid[t.first][t.second] = '.';

                        if(t.first - 1 >= 0) {
                            dfs.push({t.first - 1, t.second});
                        }
                        if(t.first + 1 < grid.size()) {
                            dfs.push({t.first + 1, t.second});
                        }
                        if(t.second - 1 >= 0) {
                            dfs.push({t.first, t.second - 1});
                        }
                        if(t.second + 1 < grid[0].size()) {
                            dfs.push({t.first, t.second + 1});
                        }
                    }

                    islands++;
                }
            }
        }

        return islands;
    }
};
