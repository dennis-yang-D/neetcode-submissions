class Solution {
public:
    // minheap with k elements
    // pop out the smallest n-k elements
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int n : nums) {
            pq.push(n);

            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
