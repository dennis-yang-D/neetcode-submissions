class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size()));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size()));

        //(i,0) and (0,i all flow into pacific)
        stack<pair<int, int>> dfs;
        for(int i = 0; i < heights.size(); i++) {
            dfs.push({i, 0});
        }
        for(int i = 0; i < heights[0].size(); i++) {
            dfs.push({0, i});
        }

        while(!dfs.empty()) {
            auto p = dfs.top();
            dfs.pop();
            if(pacific[p.first][p.second]) {continue;}
            pacific[p.first][p.second] = true;

            if(p.first - 1 >= 0 && heights[p.first - 1][p.second] >= heights[p.first][p.second]) {
                dfs.push({p.first - 1, p.second});
            }
            if(p.first + 1 <= heights.size() - 1 && heights[p.first + 1][p.second] >= heights[p.first][p.second]) {
                dfs.push({p.first + 1, p.second});
            }
            if(p.second - 1 >= 0 && heights[p.first][p.second - 1] >= heights[p.first][p.second]) {
                dfs.push({p.first, p.second - 1});
            }
            if(p.second + 1 <= heights[0].size() - 1 && heights[p.first][p.second + 1] >= heights[p.first][p.second]) {
                dfs.push({p.first, p.second + 1});
            }
        }

        for(int i = 0; i < heights.size(); i++) {
            dfs.push({i, heights[0].size()-1});
        }
        for(int i = 0; i < heights[0].size(); i++) {
            dfs.push({heights.size()-1, i});
        }

        while(!dfs.empty()) {
            auto p = dfs.top();
            dfs.pop();
            if(atlantic[p.first][p.second]) {continue;}
            atlantic[p.first][p.second] = true;

            if(p.first - 1 >= 0 && heights[p.first - 1][p.second] >= heights[p.first][p.second]) {
                dfs.push({p.first - 1, p.second});
            }
            if(p.first + 1 <= heights.size() - 1 && heights[p.first + 1][p.second] >= heights[p.first][p.second]) {
                dfs.push({p.first + 1, p.second});
            }
            if(p.second - 1 >= 0 && heights[p.first][p.second - 1] >= heights[p.first][p.second]) {
                dfs.push({p.first, p.second - 1});
            }
            if(p.second + 1 <= heights[0].size() - 1 && heights[p.first][p.second + 1] >= heights[p.first][p.second]) {
                dfs.push({p.first, p.second + 1});
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
