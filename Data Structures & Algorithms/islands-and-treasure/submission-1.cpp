class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;

        // start at every zero and go outwards, adding 1 to the distance for each of its unvisited neighbors
        // if you can decrease the distance, decrease it, otherwise return early

        stack<vector<int>> dfs;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0)
                {dfs.push({i, j, 0});

                while(!dfs.empty()) {
                    auto t = dfs.top();
                    int a = t[0];
                    int b = t[1];
                    int dist = t[2];
                    dfs.pop();

                    //cout << a << " " << b << " " << dist << endl;

                    if(a < 0 || a >= grid.size() || b < 0 || b >= grid[0].size()) {continue;}
                    if(grid[a][b] == -1) {continue;}
                    if(grid[a][b] != 0 && dist >= grid[a][b]) {continue;}
                    if(grid[a][b] != 0)
                    {
                        //cout << grid[a][b] << " ";
                        grid[a][b] = dist;
                        //cout << grid[a][b] << endl;
                    }

                    dfs.push({a-1,b,dist+1});
                    dfs.push({a+1,b,dist+1});
                    dfs.push({a,b-1,dist+1});
                    dfs.push({a,b+1,dist+1});
                }}
            }
        }
    }
};
