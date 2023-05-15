class Solution {
public:
     int dp[8000][71];
    int dfs(int row,int n,int m,vector<vector<int>>&mat,int &target,int sum){
        if(row>n){
            return abs(sum-target);
        }
        if(dp[sum][row]!=-1){
            return dp[sum][row];
        }
        int ans=INT_MAX;
        for(int j=0;j<=m;j++){
            ans=min(ans,dfs(row+1,n,m,mat,target,sum+mat[row][j]));
        }
        return dp[sum][row]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,n-1,m-1,mat,target,0);
    }
};