class Solution {
public:
    int dfs(int idx,int previdx,vector<pair<int,int>>&vp,vector<vector<int>>&dp){
        if(idx>=vp.size()){
            return 0;
        }
        if(dp[idx][previdx+1]!=-1){
            return dp[idx][previdx+1];
        }
        int take=0,not_take=0;
        if(previdx==-1 || vp[idx].second>=vp[previdx].second){
            take=vp[idx].second+dfs(idx+1,idx,vp,dp);
        }
        not_take=dfs(idx+1,previdx,vp,dp);
        return dp[idx][previdx+1]=max(take,not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>vp;
        vector<vector<int>>dp(ages.size(),vector<int>(ages.size(),-1));
        for(int i=0;i<scores.size();i++){
            vp.push_back({ages[i],scores[i]});
        }
        sort(vp.begin(),vp.end());
        return dfs(0,-1,vp,dp);
    }
};