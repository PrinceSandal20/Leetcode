class Solution {
public:
    bool dfs(int row,int col,int n,int m,vector<vector<int>>&grid1,vector<vector<int>>&grid2){
        if(row<0 || col<0 || row>n || col>m || grid2[row][col]==0){
            return true;
        }
        if(grid1[row][col]==0){
            return false;
        }
        grid2[row][col]=0;
        bool a=dfs(row+1,col,n,m,grid1,grid2);
        bool b=dfs(row-1,col,n,m,grid1,grid2);
        bool c=dfs(row,col+1,n,m,grid1,grid2);
        bool d=dfs(row,col-1,n,m,grid1,grid2);
        return a && b && c && d;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    if(dfs(i,j,n-1,m-1,grid1,grid2)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};