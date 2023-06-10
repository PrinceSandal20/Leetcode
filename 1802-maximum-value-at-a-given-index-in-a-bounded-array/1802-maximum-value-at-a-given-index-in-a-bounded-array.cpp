class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l=index,r=n-index-1;
        long long ans=0;
        int i=1,j=maxSum;
        while(i<=j){
            int mid=(i+j)>>1;
            long long l_sum=0,r_sum=0,ele=mid-1;
            if(r<=ele)
                r_sum=(ele*(ele+1))/2-((ele-r)*(ele-r+1))/2;
            else
                r_sum=(ele*(ele+1))/2+(r-ele);
            if(l<=ele)
                l_sum=(ele*(ele+1))/2-((ele-l)*(ele-l+1))/2;
            else
                l_sum=(ele*(ele+1))/2+(l-ele);
            long long sum=l_sum+r_sum+mid;
            if(sum<=maxSum){
                i=mid+1;
                ans=mid;
            }
            else{
                j=mid-1;
                //cout<<j;
            }
        }
        return ans;
    }
};