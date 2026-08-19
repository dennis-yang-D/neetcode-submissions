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
            return a.end < b.end;
        }
    };
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), sorter());

        int pastStart = -1;
        int pastEnd = -1;

        for(auto i : intervals) {
            if(i.start < pastEnd) {
                return false;
            }
            pastStart = i.start;
            pastEnd = i.end;
        }

        return true;
    }
};
