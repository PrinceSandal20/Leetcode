class Solution {
public:
    long long mode=1e9+7;
    int dfs(int low, int high, int zero, int one,int len,vector<int>&dp){
        int count=0;
        if(len>=low && len<=high){
            count++;
        }
        if(len>high){
            return 0;
        }
        if(dp[len]!=-1){
            return dp[len];
        }
        int z=dfs(low,high,zero,one,len+zero,dp);
        int o=dfs(low,high,zero,one,len+one,dp);
        return dp[len]=(count+z+o)%mode;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return dfs(low,high,zero,one,0,dp);
    }
};