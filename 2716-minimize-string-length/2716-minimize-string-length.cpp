class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<int>st;
        for(auto val:s){
            st.insert(val);
        }
        return st.size();
    }
};