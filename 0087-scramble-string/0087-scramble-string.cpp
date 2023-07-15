class Solution {
public:
    unordered_map<string,bool>m;
    bool isScramble(string a, string b) {
        string s=a+" "+b;
        if(a.compare(b)==0)return m[s]=true;
        if(m.find(s)!=m.end())return m[s];
        bool flag=false;
        int n=a.size();
        for(int i=1;i<=n-1;i++){
            //comparing first half with last && last wiith first
            if(isScramble(a.substr(0,i),b.substr(n-i,i)) && isScramble(a.substr(i,n-i),b.substr(0,n-i))){
                flag=true;
                break;
            }
            //comparing first half with first && last with last
            else if(isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i,n-i),b.substr(i,n-i))){
                flag=true;
                break;
            }
        }
        return m[s]=flag;
    }
};