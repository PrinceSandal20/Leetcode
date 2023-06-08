class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        //initialisation
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            cost[edges[i][0]][edges[i][1]]=edges[i][2];
            cost[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        //build cost matrix
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][k]==INT_MAX || cost[k][j]==INT_MAX){
                        continue;
                    }
                    if(cost[i][j]>cost[i][k]+cost[k][j]){
                        cost[i][j]=cost[i][k]+cost[k][j];
                    }
                }
            }
        }
        vector<int>dist(n,0);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    dist[i]++;
                }
            }
            ans=min(ans,dist[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(dist[i]==ans){
                return i;
            }
        }
        return 0;
    }
};