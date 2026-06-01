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
        // sort intervals
        // iterate over intervals
        // see how many starts we gotta before the end
        vector<int> starts;
        vector<int> ends;
        for (Interval i : intervals)
        {
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int indexStarts = 0;
        int indexEnds = 0;
        int openRooms = 0;
        int maxOpenRooms = 0;
        while (indexEnds < ends.size())
        { 
            if (indexStarts < starts.size() && starts[indexStarts] < ends[indexEnds])
            {
                openRooms++;
                maxOpenRooms = max(openRooms, maxOpenRooms);
                indexStarts++;
            } else
            {
                openRooms--;
                indexEnds++;
            }
        }
        return maxOpenRooms;
    }
};
