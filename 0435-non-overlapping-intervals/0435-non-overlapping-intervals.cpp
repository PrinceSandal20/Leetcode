class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto const& a, auto const & b){return a[1] < b[1];});
        int ans=-1;
        pair<int,int>p={intervals[0][0],intervals[0][1]};
        for(auto val:intervals){
            if(p.second>val[0]){
                ans++;
            }
            else{
                p.first=val[0];
                p.second=val[1];
            }
        }
        return ans;
    }
};