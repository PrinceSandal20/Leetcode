class Solution {
    private:
    bool foundsmaller(int mid,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(mid/i,n);
        }
        return count<k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int i=1,j=m*n;
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(foundsmaller(mid,m,n,k)){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
    }
};