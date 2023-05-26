class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&grid){
        if(row<0 || col<0 || row>n || col>m || grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;
        int ans=1;
        for(int i=0;i<=n;i++){
            if(grid[i][col]==1){
                ans+=dfs(i,col,n,m,grid);
            }
        }
        for(int j=0;j<=m;j++){
            if(grid[row][j]==1){
                ans+=dfs(row,j,n,m,grid);
            }
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int val=dfs(i,j,n-1,m-1,grid);
                    if(val!=1){
                        ans+=val;
                    }
                }
            }
        }
        return ans;
    }
};