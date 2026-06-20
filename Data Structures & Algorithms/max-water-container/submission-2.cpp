class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;

        while(left < right) {
            // Idea: always keep the maximum height that you currently have
            // (Based from watching the video)
            // Possible reason (from Hackernews comments)
            // If h_i < h_j, then the volume is always limited by h_i. So, there is no reason
            // to consider the height w/ h_i in future iterations. We should go to the next
            // value of h_i (which has the potential to be greater), and keep h_j
            // because we know that is a bigger value (so there's more potential from it)
            int area = (right - left) * min(heights[left], heights[right]);
            //cout << area << " ";
            maxArea = max(area, maxArea);
            if(heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxArea;
    }
};
