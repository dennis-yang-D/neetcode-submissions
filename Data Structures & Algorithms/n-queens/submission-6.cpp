class Solution {
public:
    vector<pair<int, int>> q;
    vector<vector<string>> ans;
    // represent the location of the queens as a vector of pairs
    // Each pair is the row,col coord of the queen
    // 0-indexed rows

    // For performance : we should do the backtrack based off of rows, since we can
    // eliminate an entire row each queen
    // rather than going through every coordinate
    vector<vector<string>> solveNQueens(int n) {
        backtrack(n, 0);
        return ans;
    }

    // i represents start row
    void backtrack(int n, int i) {
        if(q.size() == n) {
            ans.push_back(genBoard(q, n));
            return;
        }
        if(q.size() == n || i >= n) {
            return;
        }

        // go to the next row without making a new queen
        backtrack(n, i+1);

        for(int j = 0; j < n; j++) {
            if(isSafe(i, j, q, n))
            {
                pair<int, int> newQueen = {i, j};
                q.push_back(newQueen);
                // future queens cannot be in the same row, so let's just skip to the next row
                backtrack(n, i+1);
                q.pop_back();
            }
        }
    }

    bool isSafe(int i, int j, const vector<pair<int, int>>& queens, int n) {
        // All rows should have only one queen now, no need to check

        // now cols
        unordered_set<int> q;
        for(auto p : queens) {
            q.insert(p.first * 100 + p.second);
        }

        // check if col is taken
        for(int k = 0; k < n; k++) {
            if(q.contains(k * 100 + j)) {return false;}
        }

        // diag 1
        for(int k = 0; k < n; k++) {
            if(q.contains((i + k) * 100 + j + k)) {return false;}
            if(q.contains((i - k) * 100 + j - k)) {return false;}
            if(q.contains((i + k) * 100 + j - k)) {return false;}
            if(q.contains((i - k) * 100 + j + k)) {return false;}
        }
        return true;
    }

    vector<string> genBoard(const vector<pair<int, int>>& queens, int n) {
        vector<string> board;
        for(int i = 0; i < n; i++) {
            string row = "";
            for(int j = 0; j < n; j++) {
                row += ".";
            }
            board.push_back(row);
        }

        for(auto p : queens) {
            board[p.first][p.second] = 'Q';
        }

        return board;
    }
};
