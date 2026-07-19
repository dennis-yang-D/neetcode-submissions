class Solution {
public:
    vector<pair<int, int>> q;
    vector<vector<string>> ans;
    // represent the location of the queens as a vector of pairs
    // Each pair is the row,col coord of the queen
    // 0-indexed rows
    vector<vector<string>> solveNQueens(int n) {
        backtrack(n, 0);
        return ans;
    }

    // i represents start row
    void backtrack(int n, int i) {
        bool v = isValid(q, n);
        if(q.size() == n && v) {
            ans.push_back(genBoard(q, n));
            return;
        }
        if(q.size() == n || !v) {
            return;
        }
        if(i >= n) {
            return;
        }

        // go to the next row without making a new queen
        backtrack(n, i+1);

        for(int j = 0; j < n; j++) {
            pair<int, int> newQueen = {i, j};
            q.push_back(newQueen);
            // future queens cannot be in the same row, so let's just skip to the next row
            backtrack(n, i+1);
            q.pop_back();
        }
    }

    bool isValid(const vector<pair<int, int>>& queens, int n) {
        // All rows should have only one queen now, no need to check

        // now cols
        vector<bool> cols(n);
        for(auto p : queens) {
            if(cols[p.second] == true) {return false;}
            cols[p.second] = true;
        }

        // diags - check every pair of queens
        for(int i = 0; i < queens.size(); i++) {
            for(int j = 0; j < queens.size(); j++) {
                if(i == j) {continue;}

                int rdiff = abs(queens[i].first - queens[j].first);
                int cdiff = abs(queens[i].second - queens[j].second);

                if(rdiff == cdiff) {return false;}
            }
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
