class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Idea 1: sort the array, then run through it and find the duplicate
        // Idea: treat the nums vector like a graph, and make this a cycle detection problem?
        // Every number i corresponds to the position i in the array
        // When you hit a duplicate number, they must hit the same spot in the array but come
        // from different numbers

        // We could store this value in the number itself -> 100000 * prev value

        // [1,3,2,4,5,6,3]

        int curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            int prev = curr; // node that gets to curr
            curr = nums[curr % nums.size()] % 10000;
            int prev_node = nums[curr % nums.size()] / 100000; // prev index that got to curr
            if(prev_node == 0) {
                nums[curr % nums.size()] += 100000 * prev;
            }
            else if (prev_node != prev) {
                return nums[prev % nums.size()] % 10000;
            }
        }

        return nums[0];
    }
};
