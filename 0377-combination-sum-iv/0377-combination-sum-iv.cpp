class Solution {
public:
    int findallcombs(int target,vector<int>&nums,vector<int>&dp){
      if(dp[target]!=-1)return dp[target];
      int ans=0;
      if(target==0)ans++;
      for(int i=0;i<nums.size();i++){
        if(target>=nums[i]){
          ans+=findallcombs(target-nums[i],nums,dp);
        }
      }
      return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return findallcombs(target,nums,dp);
    }
};