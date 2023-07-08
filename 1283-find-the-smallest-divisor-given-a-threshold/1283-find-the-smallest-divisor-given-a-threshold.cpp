class Solution {
public:
    bool valid(int mid,vector<int>&nums,int threshold){
        int sum=0;
        for(auto val:nums){
            sum+=ceil(1.0*val/mid);
            if(sum>threshold){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int i=1,j=*max_element(nums.begin(),nums.end());
        while(i<=j){
            int mid=(i+j)>>1;
            if(valid(mid,nums,threshold)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};