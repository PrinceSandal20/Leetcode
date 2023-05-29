class Solution {
public:
    bool dfs(int idx,vector<int>&vis,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size() || idx<0 || vis[idx]==1){
            return false;
        }
        if(nums[idx]==0){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        vis[idx]=1;
        bool a=dfs(idx-nums[idx],vis,nums,dp);
        bool b=dfs(idx+nums[idx],vis,nums,dp);
        return dp[idx]=a || b;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0),dp(n,-1);
        return dfs(start,vis,arr,dp);
    }
};