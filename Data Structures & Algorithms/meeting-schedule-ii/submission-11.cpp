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
    int minMeetingRooms(vector<Interval>& intervals) {
        // im considering that intervals is sorted by begin (gotta sort to make sure)
        // heap that contains the min finish time on the open rooms
        // loop 
        //      -> check if heap top is smaller than my start time -> started after the end
        //      -> in casse is false: open 1 room and put into the heap -> get the maximum size of all heaps
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        for (Interval interval : intervals)
        {
            if (!minHeap.empty() && minHeap.top() < interval[0]) 
            {
                minHeap.pop();
                minHeap.push(interval[1]);
            } else
            {
                minHeap.push(interval[1]);
                ans = max(ans, minHeap.size());
            }
        }
        return ans;
    }
};
