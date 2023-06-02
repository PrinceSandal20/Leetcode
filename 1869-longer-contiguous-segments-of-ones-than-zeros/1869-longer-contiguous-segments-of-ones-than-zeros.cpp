class Solution {
public:
    int find(string s,bool flag){
        int count=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'==flag){
                count++;
            }
            else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
    bool checkZeroOnes(string s) {
        int val1=find(s,1);
        int val2=find(s,0);
        return val1>val2;
    }
};