class Solution {
public:
    string smallestString(string s) {
        bool flag=0;
        for(auto &val:s){
            if(val=='a'){
                if(flag){
                    break;
                }
            }
            else{
                val--;
                flag=1;
            }
        }
        if(!flag){
            s[s.size()-1]='z';
        }
        return s;
    }
};