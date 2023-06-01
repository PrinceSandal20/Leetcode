class Solution {
public:
    int findComplement(int n) {
        if(n==0)return 1;
        int ans=0,i=0;
        while(n>0){
            ans+=pow(2,i)*(!(n%2));
            n=n>>1;
            i++;
        }
        return ans;
    }
};