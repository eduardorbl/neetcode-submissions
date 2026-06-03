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

    bool compareIntervals (const Interval& a, const Interval& b)
    {
        return (a.start <= b.start);
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        // im considering that intervals is sorted by begin (gotta sort to make sure)
        // heap that contains the min finish time on the open rooms
        // loop 
        //      -> check if heap top is smaller than my start time -> started after the end
        //      -> in casse is false: open 1 room and put into the heap -> get the maximum size of all heaps
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return (a.start <= b.start);});
        int ans = 0;
        for (Interval interval : intervals)
        {
            if (!minHeap.empty() && minHeap.top() < interval.start) 
            {
                minHeap.pop();
                minHeap.push(interval.end);
            } else
            {
                minHeap.push(interval.end);
                ans = max(ans, (int)minHeap.size());
            }
        }
        return ans;
    }
};
