class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = piles[0];
        for(int p : piles) {
            right = max(right, p);
        }

        while(left <= right) {
            int mid = (left + right) / 2;
            if(canEatBananas(piles, h, mid)) {
                right = mid - 1; // try with less bananas
            }
            else {
                left = mid + 1; // try with more bananas
            }
        }

        return ((left + right) / 2) + 1;
    }

    bool canEatBananas(vector<int>& piles, int h, int rate) {
        int time = 0;
        for(int p : piles) {
            time += ceiling(p, rate);
        }
        return time <= h;
    }

    int ceiling(int a, int b) {
        int base = a / b;
        if(a % b > 0) {return base + 1;}
        return base;
    }
};
