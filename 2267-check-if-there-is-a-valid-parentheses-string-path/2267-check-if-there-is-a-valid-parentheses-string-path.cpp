class Solution {
public:
    bool dfs(int row,int col,int n,int m,vector<vector<char>>&grid,int k,vector<vector<vector<int>>>&dp){
        if(row>n || col>m){
            return 0;
        }
        if(grid[row][col]=='(')k++;
        else k--;
        if(k<0)return 0;
        if(row==n && col==m){
            if(k==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
        return dp[row][col][k]=dfs(row+1,col,n,m,grid,k,dp) || dfs(row,col+1,n,m,grid,k,dp);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(210,-1)));
        return dfs(0,0,n-1,m-1,grid,0,dp);
    }
};