class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>row(grid.size(),0),col(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                row[i]=max(row[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        int k=0,ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int val=grid[i][j];
                grid[i][j]=min(row[k],col[j]);
                ans+=abs(val-grid[i][j]);
            }
            k++;
        }
        return ans;
    }
};