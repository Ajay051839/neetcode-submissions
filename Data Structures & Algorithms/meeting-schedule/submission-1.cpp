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
    static bool comp(Interval interval1,Interval interval2){
        return interval1.start<interval2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=1;i<n;i++){
            if((intervals[i-1].end)>(intervals[i].start)){
               return false;
            }
        }
        return true;
    }
};
