class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=31;i>=0;i--){
            if((c & 1)==1){
                if((a & 1) ==0 && (b & 1)==0){
                    ans++;
                }
            }
            else{
                ans+=(a & 1) + (b & 1);
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return ans;
    }
};