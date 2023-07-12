class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
      vector<int>ind(n,0),ans;
      vector<int>adj[n];
      for(int i=0;i<n;i++)
      {
          for(auto val:graph[i]){
              adj[val].push_back(i);
              ind[i]++;
          }
      }
      queue<int>q;
      for(int i=0;i<n;i++)
      {
          if(ind[i]==0){
              q.push(i);
          }
      }
      while(!q.empty()){
          int node=q.front();
          q.pop();
          ans.push_back(node);
          for(auto val:adj[node]){
              ind[val]--;
              if(ind[val]==0){ 
                  q.push(val);
              }
          }
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};