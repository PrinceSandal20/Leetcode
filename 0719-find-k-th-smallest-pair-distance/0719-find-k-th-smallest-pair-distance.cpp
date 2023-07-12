class Solution {
    private:
      bool check(int mid,int k,vector<int>&nums){
          int n=nums.size();
          int j=1;
          int count=0;
          for(int i=0;i<n;i++){
              while(j<n && nums[j]-nums[i]<=mid){
                  j++;
              }
              j--;
              count+=(j-i);
          }
          return count>=k;
      }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=nums[n-1]-nums[0];
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)>>1;
            if(check(mid,k,nums)){
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