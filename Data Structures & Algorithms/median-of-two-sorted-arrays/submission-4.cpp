class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int actual_total = nums1.size() + nums2.size();
        int total_elts = (nums1.size() + nums2.size()) / 2;

        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        if(nums1.size() == 0 && nums2.size() == 0) {return 0;}
        if(nums1.size() == 0) {
            int mid_1 = (nums2.size() - 1) / 2;
            int mid_2 = nums2.size() / 2;
            return (double)(nums2[mid_1] + nums2[mid_2]) / 2.0;
        }

        int left = 0;
        int right = nums1.size() - 1;
        int mid = 0;

        while(left <= right && left < nums1.size() && right < nums1.size()) {
            mid = (left + right) / 2;
            int nums_left = total_elts - mid;

            if(nums_left < 0) {
                right = mid - 1;
            }
            else if (nums_left >= nums2.size()) {
                left = mid + 1;
            }
            else if (mid+1 >= nums1.size() || nums_left + 1 >= nums2.size() || (nums2[nums_left] < nums1[mid+1] && nums1[mid] < nums2[nums_left+1])) {
                break;
            }
            else if (nums2[nums_left] > nums1[mid+1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        cout << mid << " " << total_elts - mid << " " << actual_total;
        
        if(actual_total % 2 == 1) { // if odd #
            return min(nums1[mid], nums2[total_elts - mid]);
        }

        int min_mid = min(nums1[mid], nums2[total_elts - mid]);
        if(mid == 0) {
            return min_mid;
        }
        if(total_elts - mid == 0) {
            return min_mid;
        }
        int max_sub_mid = max(nums1[mid-1], nums2[total_elts - mid-1]);

        return (double)(min_mid + max_sub_mid) / 2.0;
    }

    //-1,0,1,1,2,2,3,4,4,5,6,6,7,7,8,9,10,11,12,12,13,14,15,342,276
};
