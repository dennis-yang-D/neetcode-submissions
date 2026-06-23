class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest_area = 0;

        for(int i = 0; i < heights.size(); i++) {
            int min_height = heights[i];
            int dist = 1;
            for(int j = i; j < heights.size(); j++) {
                min_height = min(min_height, heights[j]);
                largest_area = max(largest_area, min_height * dist);
                dist++;
            }
        }
        return largest_area;
    }
};
