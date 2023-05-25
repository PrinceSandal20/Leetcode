class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        int delr[]={1,-1,0,0};
        int delc[]={0,0,1,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if((r==0 || c==0 || r==n-1 || c==m-1) && (r!=entrance[0] || c!=entrance[1])){
                    return ans;
                }
                for(int i=0;i<4;i++){
                    int nr=r+delr[i];
                    int nc=c+delc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && maze[nr][nc]=='.'){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};