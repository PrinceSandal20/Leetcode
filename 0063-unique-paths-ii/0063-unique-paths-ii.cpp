class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(row>n || col>m || obstacleGrid[row][col]==1){
            return 0;
        }
        if(row==n && col==m){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans=dfs(row+1,col,n,m,obstacleGrid,dp)+dfs(row,col+1,n,m,obstacleGrid,dp);
        return dp[row][col]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dfs(0,0,n-1,m-1,obstacleGrid,dp);
    }
};