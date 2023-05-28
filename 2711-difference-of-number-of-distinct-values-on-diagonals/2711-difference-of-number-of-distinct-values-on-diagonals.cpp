class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                unordered_set<int>s1,s2;
                int r=i-1,c=j-1;
                while(r>=0 && c>=0){
                    s1.insert(grid[r][c]);
                    //cout<<grid[r][c]<<"<-";
                    r--,c--;
                }
                r=i+1,c=j+1;
                while(r<n && c<m){
                    s2.insert(grid[r][c]);
                    //cout<<grid[r][c]<<"->";
                    r++,c++;
                }
                ans[i][j]=abs(static_cast<int>(s1.size()-s2.size()));
            }
        }
        return ans;
    }
};