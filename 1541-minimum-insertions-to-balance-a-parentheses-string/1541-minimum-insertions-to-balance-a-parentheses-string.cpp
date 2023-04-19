class Solution {
public:
    int minInsertions(string s) {
        int ans=0,res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('){
                if(ans%2>0){
                    ans--;
                    res++;
                }
                ans+=2;
            }
            else{
                ans--;
                if(ans<0){
                    ans=ans+2;
                    res++;
                }
            }
        }
        return ans+res;
    }
};