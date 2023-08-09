class Solution {
    private:
    bool possible(int diff,int p,vector<int>&nums){
        int count_pairs=0;
        int i=0;
        while(i<nums.size()-1 && count_pairs<p){
            if(nums[i+1]-nums[i]<=diff){
                count_pairs++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count_pairs>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       int ans=INT_MAX;
       int i=0,j=nums[nums.size()-1]-nums[0];
       while(i<=j){
           int mid=(i+j)>>1;
           if(possible(mid,p,nums)){
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