class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
           int idx=upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>())-grid[i].begin();
           count+=grid[i].size()-idx;
        }
        return count;
    }
};