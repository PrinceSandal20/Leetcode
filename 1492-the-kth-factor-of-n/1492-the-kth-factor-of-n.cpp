class Solution {
public:
    int kthFactor(int n, int k) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                ans++;
                if(ans==k){
                    return i;
                }
            }
        }
        return -1;
    }
};