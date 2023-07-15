class Solution {
    private:
    int b_search(int target,vector<vector<int>>& events){
        int i=0,j=events.size()-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(events[mid][0]<=target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;
    }
    private:
    int dfs(int idx,int count,vector<vector<int>>& events,vector<vector<int>>&dp){
        if(count==0 || idx==events.size())return 0;
        if(dp[idx][count]!=-1)return dp[idx][count];
        int nxtidx=b_search(events[idx][1],events);
        return dp[idx][count]=max(events[idx][2]+dfs(nxtidx,count-1,events,dp),dfs(idx+1,count,events,dp));
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        return dfs(0,k,events,dp);
    }
};