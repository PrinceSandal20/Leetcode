class Solution {
public:
    int dfs(int idx,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>n){
            return 0;
        }
        if(dp[idx][n]!=-1){
            return dp[idx][n];
        }
        int ans=INT_MIN;
        for(int i=idx;i<=n;i++){
            int sum=nums[idx-1]*nums[i]*nums[n+1]+dfs(idx,i-1,nums,dp)+dfs(i+1,n,nums,dp);
            ans=max(ans,sum);
        }
        return dp[idx][n]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return dfs(1,n,nums,dp);
    }
};