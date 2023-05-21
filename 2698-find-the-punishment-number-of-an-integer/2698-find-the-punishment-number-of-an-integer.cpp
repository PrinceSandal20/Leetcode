class Solution {
public:
    bool check(string& s,int k,int idx,int sum) {
        if(idx>=s.size()){
            return sum==k;
        }
        int num=0;
        for (int i=idx;i<s.size();i++) {
            num=num*10+(s[i]-'0');
            if(check(s,k,i+1,sum+num)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i*i);
            if(check(s,i,0,0)){
                ans+=i*i;
            }
        }
        return ans;
    }
};