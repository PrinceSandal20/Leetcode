class Solution {
public:
    long long mode=1e9+7;
    int dfs(int row,int col,vector<vector<int>>&grid,int count,vector<vector<vector<int>>>&dp){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() ){
            return 1;
        }
        if(dp[row][col][count]!=-1){
            return dp[row][col][count];
        }
        if(count<=0){
            return 0;
        }
        int up=dfs(row-1,col,grid,count-1,dp);
        int down=dfs(row+1,col,grid,count-1,dp);
        int left=dfs(row,col-1,grid,count-1,dp);
        int right=dfs(row,col+1,grid,count-1,dp);
        int ans=(up%mode+down%mode+left%mode+right%mode)%mode;
        return dp[row][col][count]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(51,-1)));
        return dfs(startRow,startColumn,grid,maxMove,dp);
    }
};