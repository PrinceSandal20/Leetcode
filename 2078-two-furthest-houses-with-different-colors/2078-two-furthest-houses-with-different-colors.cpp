class Solution {
public:
    int dfs(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(nums[i]!=nums[j]){
            return abs(i-j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=max(dfs(i,j-1,nums,dp),dfs(i+1,j,nums,dp));
    }
    int maxDistance(vector<int>& colors) {
       vector<vector<int>>dp(colors.size(),vector<int>(colors.size(),-1));
       return dfs(0,colors.size()-1,colors,dp);
    }
};