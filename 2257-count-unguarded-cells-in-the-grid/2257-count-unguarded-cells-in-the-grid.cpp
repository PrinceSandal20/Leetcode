class Solution {
public:
    void dfs(int row,int col,int m,int n,vector<vector<int>>&mat,char ch){
        if(row<0 || col<0 || row>m || col>n || mat[row][col]==1 || mat[row][col]==2){
            return ;
        }
        if(mat[row][col]==0){
            mat[row][col]=3;
        }
        if(ch=='u'){
            dfs(row-1,col,m,n,mat,'u');
        }
        else if(ch=='d'){
            dfs(row+1,col,m,n,mat,'d');
        }
        else if(ch=='l'){
            dfs(row,col-1,m,n,mat,'l');
        }
        else{
            dfs(row,col+1,m,n,mat,'r');
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            mat[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++){
            mat[walls[i][0]][walls[i][1]]=2;
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    dfs(i-1,j,m-1,n-1,mat,'u');
                    dfs(i+1,j,m-1,n-1,mat,'d');
                    dfs(i,j-1,m-1,n-1,mat,'l');
                    dfs(i,j+1,m-1,n-1,mat,'r');
                }
            }
        }
       int ans=0;
       for(int i=0;i<mat.size();i++){
           for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]==0){
                   ans++;
               }
           }
       }
       return ans;
    }
};