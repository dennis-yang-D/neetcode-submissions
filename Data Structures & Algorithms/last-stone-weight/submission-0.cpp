class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int s : stones) {pq.push(s);}

        while(pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(s1 == s2) {continue;}

            pq.push(abs(s1 - s2));
        }

        if(pq.size() == 0) {return 0;}
        return pq.top();
    }
};
