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
        // first check if all rows are diff
        vector<bool> rows(n);
        for(auto p : queens) {
            if(rows[p.first] == true) {return false;}
            rows[p.first] = true;
        }

        // now cols
        vector<bool> cols(n);
        for(auto p : queens) {
            if(cols[p.second] == true) {return false;}
            cols[p.second] = true;
        }

        // diags - create a set w/ all pairs
        unordered_set<int> diags;
        for(auto p : queens) {
            // max n-1 squares on a diagonal (not including curr)
            // need to include both diagonals
            diags.insert(p.first * 100 + p.second);
            for(int i = 1; i < n; i++) {
                int rcheck = p.first + i;
                int ccheck = p.second + i;
                if(diags.contains(rcheck * 100 + ccheck)) {return false;}
                rcheck = p.first - i;
                ccheck = p.second - i;
                if(diags.contains(rcheck * 100 + ccheck)) {return false;}
                rcheck = p.first - i;
                ccheck = p.second + i;
                if(diags.contains(rcheck * 100 + ccheck)) {return false;}
                rcheck = p.first + i;
                ccheck = p.second - i;
                if(diags.contains(rcheck * 100 + ccheck)) {return false;}
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
