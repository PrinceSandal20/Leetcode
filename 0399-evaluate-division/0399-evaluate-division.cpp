class Solution {
public:
    void dfs(string source,string destination,unordered_map<string,vector<pair<string,double>>>&mp, unordered_map<string,int>&vis,double prod,double &ans){
        if(vis.count(source)){
            return;
        }
        if(source==destination){
            ans=prod;
            return ;
        }
        vis[source]=1;
        for(auto val:mp[source]){
            dfs(val.first,destination,mp,vis,prod*val.second,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        for(int i=0;i<queries.size();i++){
            unordered_map<string,int>vis;
            double prod=1;
            double res=-1.0;
            if(mp.count(queries[i][0])){
                dfs(queries[i][0],queries[i][1],mp,vis,prod,res);
            }
            ans.push_back(res);
        }
        return ans;
    }
};