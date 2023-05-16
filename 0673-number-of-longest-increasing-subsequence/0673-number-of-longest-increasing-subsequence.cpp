class Solution {
public:
    int n;
    pair<int,int> find(int idx,int previdx,vector<int>& nums,vector<pair<int,int>>&dp){
        if(idx==n){
            return {0,1};
        }
        if(dp[previdx+1]!=make_pair(-1,-1)){
            return dp[previdx+1];
        }
        pair<int,int> take={0,0};
        pair<int,int> not_take={0,0};
        if(previdx==-1 || nums[idx]>nums[previdx]){
            take=find(idx+1,idx,nums,dp);
            take.first++;
        }
        not_take=find(idx+1,previdx,nums,dp);
        if(take.first==not_take.first){
            return dp[previdx+1]={take.first,take.second+not_take.second};
        }
        else if(take.first>not_take.first){
            return dp[previdx+1]=take;
        }
        return dp[previdx+1]=not_take;
    }
    int findNumberOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<pair<int,int>>dp(n+1,{-1,-1});
        return find(0,-1,nums,dp).second;
    }
};