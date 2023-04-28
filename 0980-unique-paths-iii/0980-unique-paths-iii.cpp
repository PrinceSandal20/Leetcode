class Solution {
public:
    int ans=0;
    void dfs(int row,int col,int n,int m,vector<vector<int>>&grid,int count){
        if(row<0 || col<0 || row>n || col>m || grid[row][col]==-1){
            return ;
        }
        if(grid[row][col]==2){
            if(count==0){
                ans++;
            }
            return;
        }
        int x=grid[row][col];
        grid[row][col]=-1;
        dfs(row+1,col,n,m,grid,count-1);
        dfs(row-1,col,n,m,grid,count-1);
        dfs(row,col+1,n,m,grid,count-1);
        dfs(row,col-1,n,m,grid,count-1);
        grid[row][col]=x;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
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
        dfs(x,y,n-1,m-1,grid,count);
        return ans;
    }
};