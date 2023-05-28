class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>&grid,int dir,vector<vector<int>>&vis){
        if(row<0 || col<0 || row>n || col>m || (vis[row][col]==0 && grid[row][col]==0)){
            return ;
        }
        vis[row][col]=1;
        grid[row][col]=0;
        if(dir==1){
            dfs(row+1,col,n,m,grid,1,vis);
        }
        else if(dir==2){
            dfs(row-1,col,n,m,grid,2,vis);
        }
        else if(dir==3){
            dfs(row,col+1,n,m,grid,3,vis);
        }
        else if(dir==4){
            dfs(row,col-1,n,m,grid,4,vis);
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0 && !vis[i][j]){
                    vis[i][j]=1;
                    dfs(i+1,j,n-1,m-1,matrix,1,vis);
                    dfs(i-1,j,n-1,m-1,matrix,2,vis);
                    dfs(i,j+1,n-1,m-1,matrix,3,vis);
                    dfs(i,j-1,n-1,m-1,matrix,4,vis);
                }
            }
        }
    }
};