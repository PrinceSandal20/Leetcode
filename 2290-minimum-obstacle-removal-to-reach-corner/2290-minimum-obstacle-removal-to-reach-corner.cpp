class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minH;
        vis[0][0]=0;
        minH.push({0,0,0});
        int delr[]={1,-1,0,0};
        int delc[]={0,0,-1,1};
        while(!minH.empty()){
            int val=minH.top()[0];
            int r=minH.top()[1];
            int c=minH.top()[2];
            minH.pop();
            if(r==n-1 && c==m-1){
                return val;
            }
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]>grid[nr][nc]+val){
                    vis[nr][nc]=grid[nr][nc]+val;
                    minH.push({vis[nr][nc],nr,nc});
                }
            }
        }
        return vis[n-1][m-1];
    }
};