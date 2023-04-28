class Solution {
public:
    bool issame(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        return cnt<=2;
    }
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto val:adj[node]){
            if(!vis[val]){
                dfs(val,vis,adj);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        vector<int>adj[strs.size()];
        for(int i=0;i<strs.size()-1;i++){
            for(int j=i+1;j<strs.size();j++){
                if(issame(strs[i],strs[j]) && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(strs.size(),0);
        int ans=0;
        for(int i=0;i<strs.size();i++)
        {
            if(!vis[i]){
                //find no of unconnected components
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};