class Solution {
public:
    int dfs(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            ans=min(ans,nums[j+1]-nums[i-1]+dfs(i,idx-1,nums,dp)+dfs(idx+1,j,nums,dp));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
       cuts.insert(cuts.begin(),0);
       cuts.push_back(n);
       sort(cuts.begin(),cuts.end());
       vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
       return dfs(1,cuts.size()-2,cuts,dp);
    }
};