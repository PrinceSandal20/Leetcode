class Solution {
public:
    int dfs(int idx,int m,int sum,vector<int>&piles,vector<vector<int>>&dp){
        if(idx>=piles.size()){
            return 0;
        }
        if(dp[idx][m]!=-1){
            return dp[idx][m];
        }
        int ans=0,cursum=0;
        for(int i=1;i<=2*m;i++){
            int ind=idx+i-1;
            if(ind>=piles.size()){
                break;
            }
            cursum+=piles[ind];
            ans=max(sum-dfs(idx+i,max(m,i),sum-cursum,piles,dp),ans);
        }
        return dp[idx][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(2*piles.size(),-1));
        int m=1,sum=0,idx=0;
        for(auto val:piles){
            sum+=val;
        }
        return dfs(idx,m,sum,piles,dp);
    }
};