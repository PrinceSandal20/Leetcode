class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>ans=isWater;
        int n=ans.size();
        int m=ans[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int h=ans[r][c];
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>= 0 && nc<m && vis[nr][nc]==0 && isWater[nr][nc]==0){
                    q.push({nr,nc}); 
                    ans[nr][nc]=h+1;
                    vis[nr][nc]=1;
                 }
            }
        }
        return ans;
    }
};