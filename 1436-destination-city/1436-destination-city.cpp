class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>st;
        for(int i=0;i<paths.size();i++){
            st.insert(paths[i][0]);
        }
        for(int i=0;i<paths.size();i++){
            if(st.find(paths[i][1])==st.end()){
                return paths[i][1];
            }
        }
        return "";
    }
};