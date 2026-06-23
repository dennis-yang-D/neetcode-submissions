class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest_area = 0;
        vector<int> tallerHeightsToRight(heights.size());
        vector<int> tallerHeightsToLeft(heights.size());

        stack<pair<int, int>> rightStack;

        for(int i = 0; i < heights.size(); i++) {
            if(rightStack.empty()) {rightStack.push({heights[i], i});}
            else {
                while(!rightStack.empty() && heights[i] < rightStack.top().first) {
                    auto t = rightStack.top();
                    rightStack.pop();
                    tallerHeightsToRight[t.second] = i - t.second;
                }
                rightStack.push({heights[i], i});
            }
        }
        while(!rightStack.empty()) {
            auto t = rightStack.top();
            rightStack.pop();
            tallerHeightsToRight[t.second] = heights.size() - t.second;
        }
        for(int i = heights.size()-1; i > -1; i--) {
            if(rightStack.empty()) {rightStack.push({heights[i], i});}
            else {
                while(!rightStack.empty() && heights[i] < rightStack.top().first) {
                    auto t = rightStack.top();
                    rightStack.pop();
                    tallerHeightsToLeft[t.second] = t.second - i;
                }
                rightStack.push({heights[i], i});
            }
        }
        while(!rightStack.empty()) {
            auto t = rightStack.top();
            rightStack.pop();
            tallerHeightsToLeft[t.second] = t.second + 1;
        }

        for(int i = 0; i < heights.size(); i++) {
            largest_area = max(largest_area, (tallerHeightsToRight[i] + tallerHeightsToLeft[i] - 1) * heights[i]);
        }
        return largest_area;
    }
};
