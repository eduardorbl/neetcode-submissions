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
        // 0,40 - 5,10 - 15,20
        // set endsSet that contains all the endings that didnt ended yet
        //  maximum possible endsSet.size()
        vector<int> starts;
        vector<int> ends;
        for (const Interval& interval : intervals)
        {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int startIndex = 0, endIndex = 0;
        int rooms = 0;
        int result = 0;
        // starts = [0, 5, 15]
        // ends = [10, 15, 20]
        while (startIndex < starts.size())
        {
            if (starts[startIndex] < ends[endIndex])
            {
                rooms++;
                result = max(result, rooms);
                startIndex++;
            } else
            {
                rooms--;
                endIndex++;
            }
        }

        return result;
    }
};
