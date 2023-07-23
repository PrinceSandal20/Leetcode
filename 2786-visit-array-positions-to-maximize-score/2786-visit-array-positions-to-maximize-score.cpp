class Solution {
    private:
    long long dp[100005][2];
    long long  find(int  idx, int isodd,int x,vector<int>&nums){
        if(idx>=nums.size())return 0;
        if(dp[idx][isodd]!=-1)return dp[idx][isodd];
        long long skip=find(idx+1,isodd,x,nums);
        long long pick=nums[idx]+find(idx+1,(nums[idx]&1),x,nums);
        if((nums[idx]&1)!=isodd)pick-=x;
        return dp[idx][isodd]=max(pick,skip);
    }
public:
    long long maxScore(vector<int>& nums, int x) {
        memset(dp,-1,sizeof(dp));
        long long  ans=nums[0]+find(1,(nums[0]&1),x,nums);
        return ans;
    }
};