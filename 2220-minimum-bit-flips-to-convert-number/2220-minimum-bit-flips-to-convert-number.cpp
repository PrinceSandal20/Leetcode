class Solution {
public:
    int minBitFlips(int a, int b) {
        int ans=0;
        for(int i=31;i>=0;i--){
            if((b & 1)==1){
                if((a & 1)==0){
                    ans++;
                }
            }
            else{
                ans+=(a & 1);
            }
            a=a>>1;
            b=b>>1;
        }
        return ans;
    }
};