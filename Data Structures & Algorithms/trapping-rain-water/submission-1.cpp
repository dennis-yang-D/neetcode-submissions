class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());

        for(int i = 0; i < height.size() - 1; i++) {
            // first is always 0
            left_max[i+1] = max(left_max[i], height[i]);
            right_max[height.size() - 1 - i - 1] = max(right_max[height.size() - 1 - i], height[height.size() - 1 -i]);
        }

        for(int i = 0; i < height.size(); i++) {
            // find max height on left side

            area += max(min(left_max[i], right_max[i]) - height[i], 0);
        }

        return area;
    }
};
