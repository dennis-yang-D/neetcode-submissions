class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;

        for(int i = 0; i < height.size(); i++) {
            // find max height on left side
            int left = 0;
            for(int j = 0; j < i; j++) {
                left = max(left, height[j]);
            }

            // find max height on right side
            int right = 0;
            for(int j = height.size() - 1; j > i; j--) {
                right = max(right, height[j]);
            }

            area += max(min(left, right) - height[i], 0);
        }

        return area;
    }
};
