class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0]=1;
        int drow[]={1,0,1,0,-1,-1,1,-1};
        int dcol[]={1,1,0,-1,0,-1,-1,1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int val=q.front().second;
            q.pop();
            if(r==n-1 && c==m-1){
                return val;
            }
            for(int i=0;i<8;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>= 0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},val+1}); 
                }
            }
        }
        return -1;
    }
};