class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        vector<vector<int>>adjmatrix(n+1,vector<int>(n+1,0));
        vector<int>deg(n+1,0);
        for(int i=0;i<edges.size();i++){
            adjmatrix[edges[i][0]][edges[i][1]]++;
            adjmatrix[edges[i][1]][edges[i][0]]++;
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        for(int i=1;i<n+1;i++){
            for(int j=i+1;j<n+1;j++){
                for(int k=j+1;k<n+1;k++){
                    if(adjmatrix[i][j] && adjmatrix[j][k] && adjmatrix[k][i]){
                        ans=min(ans,deg[i]+deg[j]+deg[k]-6);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};