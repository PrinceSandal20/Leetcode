class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if(s.size()==1)return 1;
        int i=0,j=1,ans=0,count=0;
        while(j<s.size()){
           if(s[j]==s[j-1]){
               count++;
               while(count>1){
                   if(s[i]==s[i+1]){
                       count--;
                   }
                   i++;
               }
               if(count<=1){
                    ans=max(ans,j-i+1);
               }
           }
           else{
               if(count<=1){
                    ans=max(ans,j-i+1);
               }
           }
           j++;
        }
        return ans;
    }
};