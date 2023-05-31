class Solution {
public:
    int minJumps(vector<int>& arr){
        int n=arr.size();
        vector<int>vis(n,0);
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int ans=0;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int node=q.front();
                q.pop();
                if(node==n-1){
                    return ans;
                }
                vector<int>adj;
                adj=m[arr[node]];
                adj.push_back(node-1);adj.push_back(node+1);
                for(auto val:adj){
                    if(val>=0 && val<n && !vis[val]){
                        vis[val]=1;
                        q.push(val);
                    }
                }
                m[arr[node]]={};
            }
            ans++;
        }
        return 0;
    }
};