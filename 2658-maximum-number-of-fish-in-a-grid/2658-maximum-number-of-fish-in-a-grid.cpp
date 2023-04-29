class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(row<0 || col<0 || row>n || col>m || vis[row][col]==1 || grid[row][col]==0) {
            return 0 ;
        }
        vis[row][col]=1;
        int ans=grid[row][col]+dfs(row+1,col,n,m,grid,vis)+dfs(row-1,col,n,m,grid,vis)+dfs(row,col+1,n,m,grid,vis)+dfs(row,col-1,n,m,grid,vis);
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]>0){
                    ans=max(ans,dfs(i,j,n-1,m-1,grid,vis));
                }
            }
        }
        return ans;
    }
};