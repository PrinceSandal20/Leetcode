class Solution {
public:
    vector<int>parent;
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void uninbyrank(int u,int v,vector<int>&rank){
        int ulp_u=findparent(u); 
        int ulp_v=findparent(v); 
        if(ulp_u==ulp_v) return; 
        if(rank[ulp_u]<rank[ulp_v]) {
            parent[ulp_u]=ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int>rank(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<bool>ans;
        for(int i=0;i<requests.size();i++){
            int f=1;
            int p1=findparent(requests[i][0]);
            int p2=findparent(requests[i][1]);
            for(int j=0;j<restrictions.size();j++){
                if(findparent(restrictions[j][0])==p1 && findparent(restrictions[j][1])==p2 || findparent(restrictions[j][0])==p2 && findparent(restrictions[j][1])==p1){
                    //cout<<i<<"->"<<j<<"->"<<p1<<"->"<<p2<<endl;
                    f=0;
                    break;
                }
            }
            ans.push_back(f);
            if(f){
                uninbyrank(requests[i][0],requests[i][1],rank);
            }
        }
        return ans;
    }
};