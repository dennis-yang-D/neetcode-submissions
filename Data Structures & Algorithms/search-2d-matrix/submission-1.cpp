class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //log(m*n) = log(m) + log(n)

        // first find which row

        int left = 0;
        int right = matrix.size() - 1;

        int row = 0;
        while(left <= right) {
            row = (left + right) / 2;
            if(matrix[row][0] <= target && target <= matrix[row].back()) {
                break;
            }
            if(matrix[row].back() <= target) {
                left = row + 1;
            }
            else {
                right = row - 1;
            }
        }

        left = 0;
        right = matrix[row].size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(matrix[row][mid] == target) {return true;}
            if(matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
