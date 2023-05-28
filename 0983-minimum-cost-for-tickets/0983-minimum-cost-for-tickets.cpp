class Solution {
public:
    int find(int idx,vector<int>& days, vector<int>& costs,vector<int>&dp){
        if(idx>=days.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int day=costs[0]+find(idx+1,days,costs,dp);
        int i=idx;
        while(i<days.size() && days[i]<days[idx]+7)i++;
        int week=costs[1]+find(i,days,costs,dp);

        int j=idx;
        while(j<days.size() && days[j]<days[idx]+30)j++;
        int month=costs[2]+find(j,days,costs,dp);

        return dp[idx]=min({day,week,month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return find(0,days,costs,dp);
    }
};