class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ind(n,0),ans;
        for(int i=0;i<edges.size();i++)
        {
            ind[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            //check indegree is zero
            if(ind[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};