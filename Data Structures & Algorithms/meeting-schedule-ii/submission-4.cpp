/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    struct sorter {
        bool operator()(const Interval& a, const Interval& b) {
            return a.start < b.start;
        }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), sorter());

        priority_queue<int, vector<int>, greater<int>> pq; // store end times

        for(auto& i : intervals) {
            if(!pq.empty() && pq.top() <= i.start) // reuse room on the pq
            {
                pq.pop();
                pq.push(i.end);
            }
            else {
                pq.push(i.end);
            }
        }

        return pq.size();

    }
};
