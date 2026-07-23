class MedianFinder {
public:
    priority_queue<int, vector<int>> maxHeap; // for bottom half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; // for top half of numbers
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty()) {
            minHeap.push(num);
            return;
        }
        if(minHeap.top() <= num) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(minHeap.size() + 1 < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 == 0) {
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return minHeap.top();
    }
};
