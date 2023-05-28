class Solution {
public:
    bool dfs(int  node,vector<int>&vis,vector<int>&path,vector<int>adj[],stack<int>&st){
        vis[node]=1;
        path[node]=1;
        for(auto val:adj[node]){
            if(!vis[val]){
                if(dfs(val,vis,path,adj,st)){
                    return true;
                }
            }
            else if(path[val]){
                return true;
            }
        }
        st.push(node);
        path[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0),path(numCourses,0),adj[numCourses];
        stack<int>st;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj,st)){
                    return {};
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};