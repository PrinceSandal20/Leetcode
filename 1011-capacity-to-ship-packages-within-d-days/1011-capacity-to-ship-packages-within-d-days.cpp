class Solution {
public:
    bool check(vector<int>&arr,int days,int m){
        int res=1,sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum>m){
                res++;
                sum=arr[i];
            }
            if(res>days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days){
        int i=*max_element(weights.begin(),weights.end());
        int j=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(i<=j){
            int m=(i+j)>>1;
            if(check(weights,days,m)){
                ans=m;
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        return ans;
    }
};