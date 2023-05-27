class Solution {
public:
    int find(int idx,int n,vector<int>&nums,vector<int>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int one=nums[idx]-find(idx+1,n,nums,dp);
        int two=INT_MIN,three=INT_MIN;
        if(idx+1<n){
            two=nums[idx]+nums[idx+1]-find(idx+2,n,nums,dp);
        }
        if(idx+2<n){
            three=nums[idx]+nums[idx+1]+nums[idx+2]-find(idx+3,n,nums,dp);
        }
        return dp[idx]=max(one,max(two,three));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(50001,-1);
        int ans=find(0,stoneValue.size(),stoneValue,dp);
        if(ans>0){
            return "Alice";
        }
        else if(ans==0){
            return "Tie";
        }
        return "Bob";
    }
};