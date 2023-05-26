class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int,pair<string,string>>m;
        string ans="";
        for(int i=0;i<indices.size();i++){
            m[indices[i]]={sources[i],targets[i]};
        }
        int i=0;
        while(i<s.size()){
            if(m.count(i)){
                int jump=m[i].first.size();
                string check=m[i].first;
                //cout<<s.substr(i,jump)<<endl;
                if(s.substr(i,jump)==check){
                    ans+=m[i].second;
                    i+=jump;
                }
                else{
                    ans+=s[i];
                    i++;
                }
            }
            else{
                ans+=s[i++];
            }
        }
        return ans;
    }
};