class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans=-1;
        int n=grid.size();
        int m=grid[0].size();
        int delr[]={1,-1,0,0};
        int delc[]={0,0,1,-1};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+delr[i];
                    int nc=c+delc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        return ans==0?-1:ans;
    }
};