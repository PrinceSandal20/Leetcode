class Solution {
public:
    bool ispossible(int row,int col,int mid,vector<vector<int>>&cells){
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i=0;i<mid;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<col;i++){
            if(grid[0][i]==0){
                q.push({0,i});
                grid[0][i]=1;
            }
        }
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==row-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nc>=0 && nr<=row-1 && nc<=col-1 && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=1,high=cells.size(),ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(row,col,mid,cells)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};