class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+2,0);
        for(int i=0;i<bookings.size();i++){
            ans[bookings[i][0]]+=bookings[i][2];
            ans[bookings[i][1]+1]+=-bookings[i][2];
        }
        for(int i=1;i<ans.size();i++){
            ans[i]+=ans[i-1];
        }
        ans.erase(ans.begin());
        ans.pop_back();
        return ans;
    }
};