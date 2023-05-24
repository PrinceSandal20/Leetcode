class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>m;
        vector<vector<int>>ans;
        for(int i=0;i<groupSizes.size();i++){
            if(m[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(m[groupSizes[i]]);
                m[groupSizes[i]]={};
            }
            m[groupSizes[i]].push_back(i);
        }
        for(auto val:m){
            if(!val.second.empty()){
                ans.push_back(val.second);
            }
        }
        return ans;
    }
};