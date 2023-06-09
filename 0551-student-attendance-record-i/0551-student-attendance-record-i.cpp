class Solution {
public:
    bool checkRecord(string s) {
        int a=0,l=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                c++;
            }
            else{
                l=max(l,c);
                c=0;
                if(s[i]=='A'){
                    a++;
                }
            }
        }
        l=max(l,c);
        //cout<<l<<a;
        if(a>1 || l>=3){
            return false;
        }
        return true;
    }
};