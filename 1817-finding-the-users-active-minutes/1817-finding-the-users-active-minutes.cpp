class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans(k,0);
        unordered_map<int,set<int>>ms;
        for(int i=0;i<logs.size();i++){
            ms[logs[i][0]].insert(logs[i][1]);
        }
        for(auto val:ms){
            int pos=val.second.size();
            ans[pos-1]++;
        }
        return ans;
    }
};