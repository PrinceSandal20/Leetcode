class Solution {
public:
    int dfs(int idx,vector<int>&nums,vector<int>&vis,vector<int>&dp){
        if(vis[idx]==1 || idx>nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        vis[idx]=1;
        int ans=1+dfs(nums[idx],nums,vis,dp);
        return dp[idx]=ans;
    }
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        vector<int>dp(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if(dp[i]==-1){
                vector<int>vis(nums.size(),0);
                ans=max(ans,dfs(i,nums,vis,dp));
            }
        }
        return ans;
    }
};