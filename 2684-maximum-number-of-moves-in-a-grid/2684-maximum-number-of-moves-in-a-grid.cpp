class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp,int val){
        if(row<0 || row>n || col>m || val>=grid[row][col]){
            return -1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int a=1+dfs(row-1,col+1,n,m,grid,dp,grid[row][col]);
        int b=1+dfs(row,col+1,n,m,grid,dp,grid[row][col]);
        int c=1+dfs(row+1,col+1,n,m,grid,dp,grid[row][col]);
        return dp[row][col]=max(a,max(b,c));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(i,0,n-1,m-1,grid,dp,-1));
        }
        return ans;
    }
};