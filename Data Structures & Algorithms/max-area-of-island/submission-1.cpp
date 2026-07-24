class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        queue<pair<int, int>> bfs;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    bfs.push({i, j});
                    int curr_area = 0;
                    while(!bfs.empty()) {
                        auto p = bfs.front();
                        bfs.pop();

                        if(grid[p.first][p.second] != 1) {
                            continue;
                        }
                        curr_area++;
                        grid[p.first][p.second] = 0;

                        if(p.first - 1 >= 0) {bfs.push({p.first - 1, p.second});}
                        if(p.first + 1 < grid.size()) {bfs.push({p.first + 1, p.second});}
                        if(p.second - 1 >= 0) {bfs.push({p.first, p.second - 1});}
                        if(p.second + 1 < grid[0].size()) {bfs.push({p.first, p.second + 1});}
                    }
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};
