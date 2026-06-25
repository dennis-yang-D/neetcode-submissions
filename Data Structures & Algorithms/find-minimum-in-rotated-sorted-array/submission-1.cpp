class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums.size() == 1) {return nums[0];}

        while(left < right) {
            int mid = (left + right) / 2;
            if(nums.size() > 2 && mid > 0 && mid < nums.size() - 1 && nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]) {
                return nums[mid];
            }
            cout << mid;
            if(nums[mid] > nums[right]) {
                // this half must contain the min, since it must decrease to the min before increasing
                // search this half
                left = mid + 1;
            }
            else {
                // same logic, it must decrease to the min before increasing back to nums[mid]
                //search this half
                right = mid - 1;
            }
        }

        return nums[(left + right) / 2];
    }
};

/*
123456
234561
345612
456123
561234
612345
*/