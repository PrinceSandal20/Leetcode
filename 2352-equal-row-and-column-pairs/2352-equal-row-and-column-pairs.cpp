class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        int ans=0;
        for(auto val:grid)
        {
            //storing rows in map
            m[val]++;
        }
        for(int i=0;i<grid.size();i++)
        {
            //storing cols and check in map
            vector<int> test;
            for(int j=0;j<grid[i].size();j++)
            {
                test.push_back(grid[j][i]);
            }
            if(m.find(test)!=m.end()){
                ans+=m[test];
            }
        }
        return ans;
    }
};