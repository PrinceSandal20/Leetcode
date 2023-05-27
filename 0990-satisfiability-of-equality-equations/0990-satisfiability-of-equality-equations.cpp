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
        int ulp_u = findparent(u); 
        int ulp_v = findparent(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>rank(26,0);
        parent.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                uninbyrank(equations[i][0]-'a',equations[i][3]-'a',rank);
            }
        }
         for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                 if(findparent(equations[i][0]-'a')==findparent(equations[i][3]-'a')){
                     return false;
                 }
            }
        }
        return true;
    }
};