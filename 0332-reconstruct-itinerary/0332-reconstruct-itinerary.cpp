class Solution {
public:
    void dfs(string node,unordered_map<string,multiset<string>>&m,vector<string>&ans){
        while(!m[node].empty()){
            string a=*m[node].begin();
            m[node].erase(m[node].begin());
            dfs(a,m,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>m;
        vector<string>ans;
        for(int i=0;i<tickets.size();i++){
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs("JFK",m,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};