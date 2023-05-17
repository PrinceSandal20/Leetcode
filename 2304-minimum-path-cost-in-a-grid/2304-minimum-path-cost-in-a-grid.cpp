class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&moveCost, vector<vector<int>>&dp){
        if(row==n){
            return grid[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans=INT_MAX;
        for(int j=0;j<=m;j++){
            ans=min(ans,grid[row][col]+moveCost[grid[row][col]][j]+dfs(row+1,j,n,m,grid,moveCost,dp));
        }
        return dp[row][col]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            ans=min(ans,dfs(0,i,n-1,m-1,grid,moveCost,dp));
        }
        return ans;
    }
};