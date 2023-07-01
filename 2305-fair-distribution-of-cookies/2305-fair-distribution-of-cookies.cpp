class Solution {
public:
    int ans=INT_MAX;
    vector<int>count;
    void backtrack(int idx,int k,vector<int>&nums){
        if(idx==nums.size()){
            int mx=0;
            for(int i=0;i<k;i++){
                mx=max(mx,count[i]);
            }
            ans=min(ans,mx);
            return ;
        }
        for(int i=0;i<k;i++){
            count[i]+=nums[idx];
            backtrack(idx+1,k,nums);
            count[i]-=nums[idx];
            if(count[i]==0)break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        count.resize(k);
        backtrack(0,k,cookies);
        return ans;
    }
};