class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(row<0 || row>n || col<0 || col>m || vis[row][col]==1 || grid[row][col]==0){
            return ;
        }
        vis[row][col]=1;
        grid[row][col]=2;
        dfs(row+1,col,n,m,grid,vis);
        dfs(row-1,col,n,m,grid,vis);
        dfs(row,col+1,n,m,grid,vis);
        dfs(row,col-1,n,m,grid,vis);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int row=0,col=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    row=i,col=j;
                    break;
                }
            }
        }
        dfs(row,col,n-1,m-1,grid,vis);
        vector<pair<int,int>>v1,v2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    v1.push_back({i,j});
                }
                else if(grid[i][j]==2){
                    v2.push_back({i,j});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                ans=min(ans,abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second)-1);
            }
        }
        return ans;
    }
};