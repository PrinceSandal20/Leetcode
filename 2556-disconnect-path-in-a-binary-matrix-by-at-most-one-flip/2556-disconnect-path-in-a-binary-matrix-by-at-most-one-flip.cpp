class Solution {
public:
    bool dfs(int row,int col,int n,int m,vector<vector<int>>&grid){
        //counting unique paths
        if(row>n || col>m || grid[row][col]==0)
        {
            return 0;
        }
        if(row==n && col==m){
            return 1;
        }
        grid[row][col]=0;
        return dfs(row+1,col,n,m,grid) || dfs(row,col+1,n,m,grid);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(!dfs(0,0,n-1,m-1,grid)){
            return 1;
        }
        grid[0][0]=1;
        if(!dfs(0,0,n-1,m-1,grid)){
            return 1;
        }
        return 0;
    }
};