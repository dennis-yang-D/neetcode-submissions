class Solution {
public:
    vector<string> ans;
    string curr;
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return ans;
    }

    // invariant: currFront >= currBack
    // currFront is number of ( at the start of the loop
    void backtrack(int currFront, int currBack, int n) {
        if(currFront > n) {return;}

        if(curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }
        
        curr += "(";
        backtrack(currFront + 1, currBack, n);

        // add back parentheses
        int num_back = currFront - currBack + 1; // add 1 because the string has 1 more (
        for(int i = 0; i < num_back; i++) {
            curr += ")";
            backtrack(currFront + 1, currBack + i + 1, n);
        }

        for(int i = 0; i < num_back + 1; i++) {
            curr.pop_back();
        }
    }
};
