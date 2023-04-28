class Solution {
public:
    int ans=0;
    void dfs(int row,int col,int n,int m,vector<vector<int>>&grid,int count,vector<vector<int>>vis){
        if(row<0 || col<0 || row>n || col>m || grid[row][col]==-1  || vis[row][col]==1){
            return ;
        }
        if(grid[row][col]==2){
            if(count==0){
                ans++;
            }
            return;
        }
        vis[row][col]=1;
        dfs(row+1,col,n,m,grid,count-1,vis);
        dfs(row-1,col,n,m,grid,count-1,vis);
        dfs(row,col+1,n,m,grid,count-1,vis);
        dfs(row,col-1,n,m,grid,count-1,vis);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0,x,y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 || grid[i][j]==2){
                   count++;
                }
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        cout<<count;
        dfs(x,y,n-1,m-1,grid,count,vis);
        return ans;
    }
};