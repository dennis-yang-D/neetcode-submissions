class Solution {
public:
    int numDecodings(string s) {
        // at each character i
        // you can add 1 character from i - 1 -> corresponding to ABCDEFGHI
        // or you can add 1 character from i - 2 -> corresponding to the rest of the letters
        // if the characters actually match
        // split case based on whether current digit is a 0
        // if 0 -> can't form from i-1, can only form from i -2
        // otherwise can form from both i-1 and i-2

        vector<int> dp(s.size());

        dp[0] = s[0] != '0';
        if(s.size() == 1) {
            return dp[0];
        }


        // 1 case
        if(s[1] == '0') {
            if(isDouble(s[0], s[1])) {
                dp[1] = 1;
            }
            else {
                dp[1] = 0;
            }
        }
        else {
            if(isDouble(s[0], s[1])) {
                dp[1] = 1 + dp[0];
            }
            else {
                dp[1] = dp[0];
            }
        }
        
        for(int i = 2; i < s.size(); i++) {
            if(s[i] == '0') {
                if(isDouble(s[i-1], s[i])) {
                    dp[i] = dp[i-2];
                }
                else {
                    dp[i] = 0;
                }
            }
            else {
                if(isDouble(s[i-1], s[i])) {
                    dp[i] = dp[i-2] + dp[i-1];
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
        }

        return dp.back();
    }

    bool isDouble(char a, char b) {
        if(a == '0') {return false;}
        if(a == '1') {return true;}
        if(a == '2' && b <= '6') {return true;}
        return false;
    }
};
