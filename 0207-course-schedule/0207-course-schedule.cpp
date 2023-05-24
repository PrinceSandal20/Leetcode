class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&path){
		vis[node] = 1;
		path[node] = 1;
		for (auto val:adj[node]) {
			if (!vis[val]) {
				if(dfs(val,adj,vis,path)){
                    return true;
                }
			}
			else if (path[val]){
				return true;
			}
		}
		path[node]=0;
		return false;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses],vis(numCourses,0),path(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)){
                    return false;
                }
            }
        }
        return true;
    }
};