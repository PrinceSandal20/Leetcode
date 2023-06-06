class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>adj[n],ans(n),ind(n,0);
        for(int i=0;i<richer.size();i++){
            adj[richer[i][0]].push_back(richer[i][1]);
            ind[richer[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto val:adj[node]){
                //cout<<node<<"->"<<val<<quiet[val]<<"->"<<quiet[node]<<endl;
                if(quiet[ans[val]]>quiet[ans[node]]){
                    ans[val]=ans[node];
                }
                if(--ind[val]==0){
                    q.push(val);
                }
            }
        }
        return ans;
    }
};