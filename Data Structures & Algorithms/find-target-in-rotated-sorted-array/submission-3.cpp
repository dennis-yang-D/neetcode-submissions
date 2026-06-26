class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            cout << left << " " << right << " | ";
            if(nums[mid] == target) {return mid;}
            // Big case: left < right (correct order, proceed like standard bin search)
            if (nums[left] < nums[right]) {
                if(nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                // val must decrease when going from mid to right
                // so target < right
                if(nums[mid] > nums[right] && target <= nums[right]) {
                    left = mid + 1;
                }
                // OR target > mid (since the bigger values must be on RHS)
                else if (nums[mid] > nums[right] && target > nums[mid]) {
                    left = mid + 1;
                }
                else if (nums[mid] < nums[right] && target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                // all other cases on left
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
