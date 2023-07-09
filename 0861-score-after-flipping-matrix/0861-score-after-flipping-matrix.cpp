class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]){
                    count++;
                }
            }
            if(count*2<m){
                for(int j=0;j<m;j++){
                    if(grid[j][i]==0){
                        grid[j][i]=1;
                    }
                    else{
                        grid[j][i]=0;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum=sum*2+grid[i][j];
            }
            ans+=sum;
        }
        return ans;
    }
};