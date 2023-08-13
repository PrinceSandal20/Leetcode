class Solution {
    private:
    bool findans(int idx,int n, vector<int>&nums,vector<int>&dp){
        if(idx>=n)return true;
        if(dp[idx]!=-1)return dp[idx];
        if(idx+1<n && nums[idx]==nums[idx+1]){
            dp[idx]=findans(idx+2,n,nums,dp);
            if(dp[idx])return true;
            if(idx+2<n && nums[idx]==nums[idx+2]){
                dp[idx]=findans(idx+3,n,nums,dp);
                if(dp[idx])return true;
            }
        }
        if(idx+2<n && nums[idx+1]-nums[idx]==1 && nums[idx+2]-nums[idx+1]==1){
            dp[idx]=findans(idx+3,n,nums,dp);
            if(dp[idx])return true;
        }
        return dp[idx]=false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return findans(0,n,nums,dp);
    }
};