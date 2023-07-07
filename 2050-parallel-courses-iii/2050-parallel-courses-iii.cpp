class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n],ind(n,0),ctime(n,0);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            ind[relations[i][1]-1]++;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push({0,i});
            }
        }
        while(!q.empty()){
            int t=q.front().first;
            int node=q.front().second;
            q.pop();
            int comptime=t+time[node];
            ctime[node]=comptime;
            for(auto val:adj[node]){
                ctime[val]=max(ctime[val],comptime);
                if(--ind[val]==0){
                    q.push({ctime[val],val});
                }
            }
        }
        return *max_element(ctime.begin(),ctime.end());
    }
};