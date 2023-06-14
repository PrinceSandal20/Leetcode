class Solution {
public:
    bool dfs(int idx,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==nums.size()-1){
            return true;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        bool isValid=false;
        for(int i=idx+1;i<nums.size();i++){
            if(nums[i]==nums[idx]+k-1){
                isValid=isValid||dfs(i,k-1,nums,dp);
            }
            else if(nums[i]==nums[idx]+k){
                isValid=isValid||dfs(i,k,nums,dp);
            }
            else if(nums[i]==nums[idx]+k+1){
                isValid=isValid||dfs(i,k+1,nums,dp);
            }
            if(isValid){
                return dp[idx][k]=1;
            }
        }
        return dp[idx][k]=0;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return dfs(0,0,stones,dp);
    }
};