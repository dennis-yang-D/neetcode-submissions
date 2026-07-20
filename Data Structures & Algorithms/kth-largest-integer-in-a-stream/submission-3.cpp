class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq_greater; // k-1 elements
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums) {
            pq_greater.push(i);
        }
        while(pq_greater.size() > k) {
            pq_greater.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        pq_greater.push(val);
        if(pq_greater.size() > k) {
            pq_greater.pop();
        }
        return pq_greater.top();
    }
};
