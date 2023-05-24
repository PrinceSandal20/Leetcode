class Solution {
public:
     bool issame(unordered_map<string,int>m,string cat,int siz) {
        for(int j=0;j<cat.size();j+=siz) {
            string w=cat.substr(j,siz);
            if(m.find(w)!=m.end()) {
                if(--m[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int window=words.size()*words[0].size();
        vector<int>ans;
        unordered_map<string,int>m;
        for(auto val:words){
            m[val]++;
        }
        int i=0,j=0;
        string cat="";
        while(j<s.size()){
            cat+=s[j];
            if(j-i+1<window){
                j++;
            }
            else if(j-i+1==window){
                if(issame(m,cat,words[0].size())){
                    ans.push_back(i);
                }
                cat.erase(cat.begin());
                i++,j++;
            }
        }
        return ans;
    }
};