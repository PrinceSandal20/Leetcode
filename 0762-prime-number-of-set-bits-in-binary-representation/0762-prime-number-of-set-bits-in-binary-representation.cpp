class Solution {
public:
    bool isprime(int a)
    {
        if(a==1)return false;
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int idx=i,cnt=0;
            while(idx>0){
                if(idx%2!=0){
                    cnt++;
                }
                idx=idx>>1;
            }
            if(isprime(cnt)){
                ans++;
            }
        }
        return ans;
    }
};