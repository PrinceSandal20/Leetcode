class Solution {
public:
    int dfs(int  node,unordered_map<int,vector<int>>&mp,unordered_set<int>&vis){
        vis.insert(node);
        int count=0;
        for(auto val:mp[node]){
            if(vis.count(val)==0){
                count+=dfs(val,mp,vis);
            }
        }
        return count+1;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<bombs.size();i++){
            for(int j=0;j<bombs.size();j++){
                if(i!=j){
                    int u1=bombs[i][0],v1=bombs[i][1];
                    int u2=bombs[j][0],v2=bombs[j][1];
                    //we are checkin for every pair using distance formula
                    if((long long)bombs[i][2]*bombs[i][2]>=(long long)(u1-u2)*(u1-u2)+(long long)(v1-v2)*(v1-v2)){
                        //cout<<i<<"->"<<j<<endl;
                        mp[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<bombs.size();i++){
            unordered_set<int>vis;
            ans=max(ans,dfs(i,mp,vis));
        }
        return ans;
    }
};