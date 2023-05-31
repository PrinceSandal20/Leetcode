class Solution {
public:
    void dfs(int row,int col,int n,int m,int &x,int &y,vector<vector<int>>&land){
        if(row<0 || col<0 || row>n || col>m || land[row][col]==0){
            return ;
        }
        x=max(x,row);
        y=max(y,col);
        land[row][col]=0;
        dfs(row+1,col,n,m,x,y,land);
        dfs(row-1,col,n,m,x,y,land);
        dfs(row,col+1,n,m,x,y,land);
        dfs(row,col-1,n,m,x,y,land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    vector<int>res;
                    res.push_back(i);
                    res.push_back(j);
                    int x=-1,y=-1;
                    dfs(i,j,n-1,m-1,x,y,land);
                    if(x==-1 && y==-1){
                        res.push_back(i);
                        res.push_back(j);
                    }
                    else{
                        res.push_back(x);
                        res.push_back(y);
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};