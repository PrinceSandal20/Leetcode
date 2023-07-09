class Solution {
    private:
     bool canplace(int mid,int m,vector<int>&nums){
         int count=0;
         for(int i=0;i<nums.size();i++){
             count+=ceil(1.0*nums[i]/mid);
         }
         return count<=m;
     }
public:
    int minimizedMaximum(int m, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int n=quantities.size();
        int i=1,j=*max_element(quantities.begin(),quantities.end());
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)>>1;
            if(canplace(mid,m,quantities)){
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