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
        vector<int> v(1e6+1, 0);
        for(Interval i : intervals){
            v[i.start]++;
            v[i.end]--;
        }
        int ans = v[0];
        for(int i=1;i<v.size();i++){
            v[i] = v[i]+v[i-1];
            ans = max(ans, v[i]);
        }
        return ans;
    }
};
