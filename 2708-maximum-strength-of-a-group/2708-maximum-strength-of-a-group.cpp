class Solution {
public:
    long long dfs(int idx,long long prod,int zeropick,int n,vector<int>&nums){
        if(idx>=n){
            if(zeropick==0){
                return INT_MIN;
            }
            return prod;
        }
        long long take=dfs(idx+1,prod*nums[idx],zeropick+1,n,nums);
        long long not_take=dfs(idx+1,prod,zeropick,n,nums);
        return max(take,not_take);
    }
    long long maxStrength(vector<int>& nums) {
        return dfs(0,1,0,nums.size(),nums);
    }
};