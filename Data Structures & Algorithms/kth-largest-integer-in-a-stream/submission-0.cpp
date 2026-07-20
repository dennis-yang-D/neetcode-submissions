class KthLargest {
public:
    priority_queue<int> pq;
    int num = 0;
    KthLargest(int k, vector<int>& nums) {
        // keep a minheap, with n-k elements
        // the top element must be the n-kth smallest element, same as the kth largest elt
        int nk = nums.size() - k;

        for(int i : nums) {
            pq.push(i);
        }
        num = k;
    }
    
    int add(int val) {
        pq.push(val);

        vector<int> v;
        for(int i = 0; i < num-1; i++) {
            v.push_back(pq.top());
            pq.pop();
        }
        int c = pq.top();
        for(int n : v) {
            pq.push(n);
        }
        return c;
    }
};
