class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>grid;
        grid=board;
        int n=board.size();
        int m=board[0].size();
        int delr[]={1,1,1,0,0,-1,-1,-1};
        int delc[]={0,1,-1,1,-1,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int count=0;
                    for(int k=0;k<8;k++){
                        int nr=i+delr[k];
                        int nc=j+delc[k];
                        if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1){
                            if(grid[nr][nc]==1){
                                count++;
                            }
                        }
                    }
                    if(count==3){
                        board[i][j]=1;
                    }
                }
                else{
                    int count=0;
                    for(int k=0;k<8;k++){
                        int nr=i+delr[k];
                        int nc=j+delc[k];
                        if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1){
                            if(grid[nr][nc]==1){
                                count++;
                            }
                        }
                    }
                    if(count<2 || count>3){
                        board[i][j]=0;
                    }
                }
            }
        }
    }
};