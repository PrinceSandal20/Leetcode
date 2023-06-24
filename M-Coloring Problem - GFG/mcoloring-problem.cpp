//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isright(int node,int n,int m,vector<int>adj[],int color[]){
        for(auto val:adj[node]){
            if(color[val]==m)return false;
        }
        return true;
    }
    bool dfs(int node,int n,int m,vector<int>adj[],int color[]){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(isright(node,n,i,adj,color)){
                color[node]=i;
                if(dfs(node+1,n,m,adj,color)){
                    return true;
                }
                color[i]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int color[n];
        for(int i=0;i<n;i++)color[i]=0;
        return dfs(0,n,m,adj,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends