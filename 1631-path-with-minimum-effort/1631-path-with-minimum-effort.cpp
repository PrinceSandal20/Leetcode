class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minH;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        minH.push({0,{0,0}});
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        while(!minH.empty()){
            int diff=minH.top().first;
            int row=minH.top().second.first;
            int col=minH.top().second.second;
            minH.pop();
            if(row==n-1 && col==m-1)
                return diff;
            for(int i=0;i<4;i++){
                int nr=row+delr[i];
                int nc=col+delc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int new_diff=max(abs(heights[row][col]-heights[nr][nc]),diff);
                    if(new_diff<dis[nr][nc]){
                        dis[nr][nc]=new_diff;
                        minH.push({new_diff,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};