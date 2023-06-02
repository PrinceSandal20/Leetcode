class Solution {
public:
    bool checkOnesSegment(string s) {
        int count=0,ans=0,flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1'){
                count++;
            }
            else{
                ans=max(ans,count);
                if(count){
                    flag++;
                }
                if(flag>1){
                    return false;
                }
                count=0;
            }    
        }
        ans=max(ans,count);
        if(count>=1 && flag==1){
            return false;
        }
        return true;
    }
};