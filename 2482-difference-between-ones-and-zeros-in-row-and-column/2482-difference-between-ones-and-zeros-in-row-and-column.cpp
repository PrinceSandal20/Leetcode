class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int,int>rowone,rowzero,colone,colzero;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    rowzero[i]++;
                }
                else if(grid[i][j]==1){
                    rowone[i]++;
                }
            }
        }
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==0){
                    colzero[j]++;
                }
                else if(grid[i][j]==1){
                    colone[j]++;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int val=rowone[i]+colone[j]-rowzero[i]-colzero[j];
                grid[i][j]=val;
            }
        }
        return grid;
    }
};