class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // max distance of a fresh fruit to any rotten fruit
        int dist = 10000;

        stack<vector<int>> dfs;
        int num_zeroes = 0;
        int num_twos = 0;
        int num_ones = 0;

        vector<vector<int>> dists(grid.size());
        for(int a = 0; a < grid.size(); a++) {
            for(int b = 0; b < grid[0].size(); b++) {
                dists[a].push_back(10000);
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0 ) {num_zeroes++;}
                if(grid[i][j] == 1 ) {num_ones++;}
                if(grid[i][j] == 2) {
                    num_twos++;
                    dfs.push({i, j, 0});
                }
            }
        }
        if(num_zeroes == grid.size() * grid[0].size()) {return 0;}
        if(num_twos > 0 && num_ones == 0) {return 0;}

        while(!dfs.empty()) {
            auto t = dfs.top();
            dfs.pop();

            if(t[0] < 0 || t[0] >= grid.size() || t[1] < 0 || t[1] >= grid[0].size()) {continue;}
            if(grid[t[0]][t[1]] == 0) {continue;}
            if(grid[t[0]][t[1]] == 2 && t[2] > 0) {continue;}
            if(grid[t[0]][t[1]] == 1 && dists[t[0]][t[1]] <= t[2]) {continue;}

            if(grid[t[0]][t[1]] == 1) {
                dists[t[0]][t[1]] = t[2];
            }

            dfs.push({t[0]-1, t[1], t[2] + 1});
            dfs.push({t[0]+1, t[1], t[2] + 1});
            dfs.push({t[0], t[1]-1, t[2] + 1});
            dfs.push({t[0], t[1]+1, t[2] + 1});
        }

        bool flag = true;
        int max_minutes = -1;
        for(int a = 0; a < grid.size(); a++) {
            for(int b = 0; b < grid[0].size(); b++) {
                if(grid[a][b] == 1 && dists[a][b] == 10000) {
                    max_minutes = -1;
                    break;
                }
                if(grid[a][b] == 1 && dists[a][b] < 10000) {
                    max_minutes = max(max_minutes, dists[a][b]);
                }
            }
        }
        //cout << flag;
        return max_minutes;
    }
};
