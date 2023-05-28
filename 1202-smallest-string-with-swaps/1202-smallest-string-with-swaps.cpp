class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void unionb(int u,int v){
        int ul_u=findparent(u);
        int ul_v=findparent(v);
        if(ul_u==ul_v){
            return ;
        }
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.resize(s.size(),0);
        rank.resize(s.size(),0);
        for(int i=0;i<s.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<pairs.size();i++){
            unionb(pairs[i][0],pairs[i][1]);
        }
        unordered_map<int,vector<char>>mp;
        for(int i=0;i<s.size();i++){
            mp[findparent(i)].push_back(s[i]);
        }
        for(auto &val:mp){
            sort(val.second.begin(),val.second.end());
        }
        for(int i=0;i<s.size();i++){
            s[i]=*mp[parent[i]].begin();
            mp[parent[i]].erase(mp[parent[i]].begin());
        }
        return s;
    }
};