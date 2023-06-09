class Solution {
public:
    int dfs(int row,int col1,int col2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(col1<0 || col2<0 || col1>m || col2>m){
            return -1e8;
        }
        if(dp[row][col1][col2]!=-1){
            return dp[row][col1][col2];
        }
        if(row==n){
            if(col1==col2){
                return grid[row][col1];
            }
            else if(col1!=col2){
                return grid[row][col1]+grid[row][col2];
            }
        }
        int mx=-1e8;
        for(int i=-1;i<=+1;i++){
            for(int j=-1;j<=+1;j++){
                int val=0;
                if(col1==col2){
                    val=grid[row][col1];
                }
                else if(col1!=col2){
                    val=grid[row][col1]+grid[row][col2];
                }
                val+=dfs(row+1,col1+i,col2+j,n,m,grid,dp);
                mx=max(mx,val);
            }
        }
        return dp[row][col1][col2]=mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return dfs(0,0,m-1,n-1,m-1,grid,dp);
    }
};