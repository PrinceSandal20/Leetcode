class Solution {
public:
    vector<int>parent,rank;
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void uninbyrank(int u,int v){
        int ul_u=findparent(u); 
        int ul_v=findparent(v); 
        if(ul_u==ul_v) return; 
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v; 
        }
        else if(rank[ul_v]<rank[ul_u]){
            parent[ul_v]=ul_u; 
        }
        else{
            parent[ul_v]=ul_u; 
            rank[ul_u]++; 
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(m.find(mail)!=m.end()){
                    uninbyrank(i,m[mail]);
                }
                else{
                    m[mail]=i;
                }
            }
        }
        vector<string>adj[n];
        for(auto val:m){
            string s=val.first;
            int idx=findparent(val.second);
            adj[idx].push_back(s);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(adj[i].size()!=0){
                sort(adj[i].begin(),adj[i].end());
                vector<string>res;
                res.push_back(accounts[i][0]);
                for(auto val:adj[i]){
                    res.push_back(val);
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};