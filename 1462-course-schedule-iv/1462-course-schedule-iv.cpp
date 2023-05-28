class Solution {
public:
    bool dfs(int start,int end,vector<int>adj[],vector<int>&vis){
        vis[start]=1;
        if(start==end){
            return true;
        }
        for(auto val:adj[start]){
            if(!vis[val]){
                if(dfs(val,end,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            vector<int>vis(numCourses,0);
            if(dfs(queries[i][0],queries[i][1],adj,vis)){
                ans[i]=1;
            }
        }
        return ans;
    }
};