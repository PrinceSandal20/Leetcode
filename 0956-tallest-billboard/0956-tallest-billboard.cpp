class Solution {
public:
    int find(int idx,int diff,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(diff==0){
                return 0;
            }
            else{
                return -1e9;
            }
        }
        if(dp[idx][5000+diff]!=-1){
            return dp[idx][5000+diff];
        }
        int not_take=find(idx+1,diff,nums,dp);
        int take1=nums[idx]+find(idx+1,diff+nums[idx],nums,dp);
        int take2=find(idx+1,diff-nums[idx],nums,dp);
        return dp[idx][5000+diff]=max({not_take,take1,take2});
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>dp(rods.size(),vector<int>(10000,-1));
        return find(0,0,rods,dp);
    }
};