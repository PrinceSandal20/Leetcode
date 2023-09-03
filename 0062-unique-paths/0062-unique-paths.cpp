class Solution {
public:
    int dfs(int row,int col,int m,int n,vector<vector<int>>&path,vector<vector<int>>&dp){
        if(row>m || col>n){
            return 0;
        }
        if(row==m && col==n){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans=dfs(row+1,col,m,n,path,dp)+dfs(row,col+1,m,n,path,dp);
        return dp[row][col]=ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>path(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dfs(0,0,m-1,n-1,path,dp);
    }
};