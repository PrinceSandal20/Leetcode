class Solution {
public:
    long long dfs(int idx,int n,vector<vector<int>>& questions,vector<long long>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        long long take=(long long)questions[idx][0]+dfs(idx+questions[idx][1]+1,n,questions,dp);
        long long not_take=dfs(idx+1,n,questions,dp);
        return dp[idx]=max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return dfs(0,n,questions,dp);
    }
};