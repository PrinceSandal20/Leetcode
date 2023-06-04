class Solution {
public:
    vector<int>parent,rank;
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    bool unionb(int u,int v){
        int ul_u=findparent(u);
        int ul_v=findparent(v);
        if(ul_u==ul_v){
            return true;
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
        return false;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        parent.resize(n,1);
        rank.resize(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }    
        for(int i=0;i<n;i=i+2){
            unionb(row[i],row[i+1]);
        }
        for(int i=0;i<n;i=i+2){
            if(unionb(i,i+1)==false){
                ans++;
            }
        }
        return ans;
    }
};