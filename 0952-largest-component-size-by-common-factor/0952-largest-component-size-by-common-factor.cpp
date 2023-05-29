class Solution {
public:
    vector<int>parent,siz;
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
        if(siz[ul_u]<siz[ul_v]) {
            parent[ul_u]=ul_v;
            siz[ul_v]+=siz[ul_u];
        }
        else{
            parent[ul_v]=ul_u;
            siz[ul_u]+=siz[ul_v];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        parent.resize(mx+2,0);
        siz.resize(mx+2,1);
        for(int i=0;i<=mx+1;i++){
            parent[i]=i;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    unionb(nums[i],j);
                    unionb(nums[i]/j,j);
                }
            }
        }
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int val=findparent(nums[i]);
            m[val]++;
            ans=max(ans,m[val]);
        }
        return ans;
    }
};