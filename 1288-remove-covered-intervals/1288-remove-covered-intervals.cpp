class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        int ans = 0, maxEnd = -1;
        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                ans++;
                maxEnd = interval[1];
            }
        }
        return ans;
    }
};