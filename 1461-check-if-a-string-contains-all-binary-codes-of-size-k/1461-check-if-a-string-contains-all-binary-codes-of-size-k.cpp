class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int i=0,j=0;
        string temp="";
        while(j<s.size()){
            temp.push_back(s[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                st.insert(temp);
                temp.erase(temp.begin());
                i++,j++;
            }
        }
        k=1<<k;
        if(st.size()==k)return true;
        return false;
    }
};