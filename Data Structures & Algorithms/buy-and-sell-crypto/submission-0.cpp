class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 10, 1, 5, 6, 7, 6, 10
        //2 pointers start at x[0] = 10
        // when right + 1 >= right - advance right ptr, the value continues to increase
        // when right + 1 < right - if right + 1 >= left, advance right ptr. If right + 1 < left, left = right + 1
        // bc every future value of right that's greater than current left, will generate even more profit
        // if we set left = right + 1 (since right + 1 < left so more profit potential!)

        int left = 0;
        int right = 0;
        int max_profit = 0;

        while(right < prices.size() - 1) {
            //cout << left << " " << right << " | ";
            max_profit = max(max_profit, prices[right] - prices[left]);
            if(prices[right + 1] >= prices[right]) {
                right++;
            }
            else if (prices[right + 1] > prices[left]) {
                right++;
            }
            else {
                left = right+1;
                right++;
            }
        }
        max_profit = max(max_profit, prices[right] - prices[left]);

        return max_profit;
    }
};
