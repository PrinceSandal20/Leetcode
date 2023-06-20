class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long avg=(k<<1)+1;
        vector<int>ans(nums.size(),-1);
        if(k==0){
            return nums;
        }
        if(avg>nums.size()){
            return ans;
        }
        vector<long long >pref(nums.size()+1,0);
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }
        pref.insert(pref.begin(),0);
        for(int i=k+1;i<nums.size()-k+1;i++){
            long long left=pref[i-k-1],right=pref[i+k];
            long long sum=(right-left)/avg;
            ans[i]=sum;
        }
        ans.erase(ans.begin());
        ans.insert(ans.end(),-1);
        return ans;
    }
};