class Solution {
public:
    int maxPower(string s) {
        if(s.size()==1){
            return 1;
        }
        int ans=0,count=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                count++;
                ans=max(ans,count);
            }
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        return ans;
    }
};