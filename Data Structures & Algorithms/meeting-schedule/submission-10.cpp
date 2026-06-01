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
    bool canAttendMeetings(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> endMinHeap;
        
        if (intervals.size() == 0) return true;
        if (intervals.size() == 1) return true;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.end < b.end;});
        int actualEnd = intervals[0].end;
        int index_intervals = 1;
        while (index_intervals < intervals.size())
        {
            if (actualEnd > intervals[index_intervals].start)
            {
                return false;
            }
            actualEnd = intervals[index_intervals].end;
            index_intervals++;
        }
        return true;
    }
};
