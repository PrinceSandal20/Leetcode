class Solution {
public:
    int mode=1e9+7;
    long long dfs(int row,int col,int n,int m,vector<vector<int>>&grid,int k,int sum,vector<vector<vector<int>>>&dp){
        if(row>n || col>m){
            return 0;
        }
        if(row==n && col==m && (sum+grid[row][col])%k==0){
            return 1;
        }
        if(dp[row][col][sum]!=-1){
            return dp[row][col][sum];
        }
        int side=dfs(row,col+1,n,m,grid,k,(sum+grid[row][col])%k,dp);
        int down=dfs(row+1,col,n,m,grid,k,(sum+grid[row][col])%k,dp);
        return dp[row][col][sum]=(side+down)%mode;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return dfs(0,0,n-1,m-1,grid,k,0,dp);
    }
};