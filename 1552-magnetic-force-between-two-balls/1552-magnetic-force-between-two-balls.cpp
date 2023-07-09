class Solution {
    private:
     bool canplace(int dist,int cows,vector<int>&nums){
         int count=1,last=nums[0];
         for(int i=1;i<nums.size();i++){
             if(nums[i]-last>=dist){
                 count++;
                 last=nums[i];
             }
         }
         return count>=cows; //means we are able to place all cows or not
     }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int i=1,j=position[n-1]-position[0];
        int ans=INT_MIN;
        while(i<=j){
            int mid=(i+j)>>1;
            if(canplace(mid,m,position)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};