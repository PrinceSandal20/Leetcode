class Solution {
public:
    int delr[4]={1,0,-1,0};
    int delc[4]={0,1,0,-1};
    bool dfs(int row,int col,int n,int m,vector<vector<int>>&grid,vector<int>&ans,vector<vector<int>>&vis)
    {
        vis[row][col]=1;
        bool flag=1;
        for(int i=0;i<4;i++){
            int r=row+delr[i];
            int c=col+delc[i];
            if(r>=0 && c>=0 && r<n && c<m){
                if(grid[row][col]<grid[r][c] && vis[r][c]==0 && dfs(r,c,n,m,grid,ans,vis)){
                    return true;
                }
                else if(grid[row][col]<grid[r][c]){
                    flag=0;
                }
            }
        }
        if(flag){
            ans[0]=row;
            ans[1]=col;
        }
        return flag;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans(2);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && dfs(i,j,n,m,mat,ans,vis)){
                    return ans;
                }
            }
        }
        return ans;
    }
};