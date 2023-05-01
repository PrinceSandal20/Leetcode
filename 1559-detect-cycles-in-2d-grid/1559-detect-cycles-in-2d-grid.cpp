class Solution {
public:
    bool dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid,char ch,int dir){
        int n=grid.size();
        int m=grid[0].size();
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col]!=ch){
            return false;
        }
        if(vis[row][col]==1){
            return true;
        }
        vis[row][col]=1;
        return (dir!=2 && dfs(row+1,col,vis,grid,ch,1)) || (dir!=1 && dfs(row-1,col,vis,grid,ch,2)) || (dir !=4 && dfs(row,col+1,vis,grid,ch,3)) || (dir!=3 && dfs(row,col-1,vis,grid,ch,4));
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && dfs(i,j,vis,grid,grid[i][j],0)){
                    return true;
                }
            }
        }
        return false;
    }
};