class Solution {
public:
    // Quickselect
    int findKthLargest(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = -1 * nums[i];
        }
        return -1 * select(nums, 0, nums.size() - 1, k-1);
    }

    int select(vector<int>& nums, int left, int right, int k) {
        if(left == right) {
            return nums[left];
        }
        int pivotIndex = right;
        int i = partition(nums, left, right, pivotIndex);

        if(i == k) {
            return nums[i];
        }
        else if (i > k) {
            return select(nums, left, i - 1, k);
        }
        else {
            return select(nums, i+1, right, k);
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivotindex) {
        // find pivot
        int pivot = nums[pivotindex];
        swap(nums[pivotindex], nums[right]); // first swap pivot to right
        // temp pivot index
        int i = left;
        for(int j = left; j < right; j++) {
            if(nums[j] <= pivot) {
                swap(nums[j], nums[i]);
                i++;
            }
        }

        swap(nums[right], nums[i]); // swap back pivot to correct place
        return i; // this is the correct position of the pivot
    }
};
