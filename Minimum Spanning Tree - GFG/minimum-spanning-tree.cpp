//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int>parent,rank;
	int findparent(int node){
	    if(node==parent[node])
	    {
	        return node;
	    }
	    return parent[node]=findparent(parent[node]);
	}
	void unionb(int u,int v){
	    int ul_u=findparent(u);
	    int ul_v=findparent(v);
	    if(ul_u==ul_v)return ;
	    if(rank[ul_u]<rank[ul_v]){
	        parent[ul_u]=ul_v;
	    }
	    else if(rank[ul_u]>rank[ul_v]){
	        parent[ul_v]=ul_u;
	    }
	    else{
	         parent[ul_v]=ul_u;
	         rank[ul_u]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        parent.resize(V,0);
        rank.resize(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        vector<pair<int,pair<int,int>>>edge;
        for(int i=0;i<V;i++){
            for(auto val:adj[i]){
                int adjnode=val[0];
                int wt=val[1];
                edge.push_back({wt,{i,adjnode}});
            }
        }
        sort(edge.begin(),edge.end());
        int ans=0;
        for(int i=0;i<edge.size();i++){
            int wt=edge[i].first;
            int node=edge[i].second.first;
            int adjnode=edge[i].second.second;
            if(findparent(node)!=findparent(adjnode)){
                ans+=wt;
                unionb(node,adjnode);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends