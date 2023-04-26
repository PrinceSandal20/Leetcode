class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>v;
        string temp="";
        int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        v.push_back(temp);
        for(auto val:v){
            int siz=val.size();
            len=max(len,siz);
        }
        vector<vector<char>>test(v.size(),vector<char>(len,' '));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                test[i][j]=v[i][j];
                cout<<test[i][j]<<endl;
            }
        }
        vector<string>ans;
        for(int j=0;j<test[0].size();j++){
            string st="",x="";
            for(int i=0;i<test.size();i++){
                if(test[i][j]!=' '){
                    st=st+x+test[i][j];
                    x="";
                }
                else{
                    x+=" ";
                }
            }
            ans.push_back(st);
        }
        return ans;
    }
};