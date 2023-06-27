class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>m;
    int nodes;
    Graph(int n, vector<vector<int>>& edges) {
        nodes=n;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        m[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dis(nodes,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        minH.push({0,node1});
        dis[node1]=0;
        while(!minH.empty()){
            int d=minH.top().first;
            int nod=minH.top().second;
            minH.pop();
            for(auto val:m[nod]){
                int nd=val.first;
                int dist=val.second;
                if(dis[nd]>dis[nod]+dist){
                    dis[nd]=dis[nod]+dist;
                    minH.push({dis[nd],nd});
                }
            }
        }
        return dis[node2]==INT_MAX?-1:dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */