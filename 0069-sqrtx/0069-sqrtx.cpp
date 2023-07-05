class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int i=1,j=x;
        int ans=1;
        while(i<=j){
            long long mid=i+(j-i)/2;
            long long val=mid*mid;
            if(val>x){
                j=mid-1;
            }
            else{
                ans=mid;
                i=mid+1;
            }
        }
        return ans;
    }
};