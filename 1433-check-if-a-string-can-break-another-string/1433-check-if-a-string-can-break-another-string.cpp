class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int f1=0,f2=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]<s2[i]){
                f1=1;
            }
            if(s2[i]<s1[i]){
                f2=1;
            }
        }
        if(f1 && f2){
            return false;
        }
        return true;
    }
};