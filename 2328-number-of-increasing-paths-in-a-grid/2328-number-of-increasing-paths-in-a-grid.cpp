class Solution {
public:
    long long mode=1e9+7;
    int dfs(int row,int col,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int a=0,b=0,c=0,d=0;
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(row+1<=n && matrix[row][col]<matrix[row+1][col]){
            a=dfs(row+1,col,n,m,matrix,dp);
        }
        if(row-1>=0 && matrix[row][col]<matrix[row-1][col]){
            b=dfs(row-1,col,n,m,matrix,dp);
        }
        if(col+1<=m && matrix[row][col]<matrix[row][col+1]){
            c=dfs(row,col+1,n,m,matrix,dp);
        }
        if(col-1>=0 && matrix[row][col]<matrix[row][col-1]){
            d=dfs(row,col-1,n,m,matrix,dp);
        }
        return dp[row][col]=((((a+b)%mode+c)%mode+d)%mode+1)%mode;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+dfs(i,j,n-1,m-1,grid,dp))%mode;
            }
        }
        return ans;
    }
};