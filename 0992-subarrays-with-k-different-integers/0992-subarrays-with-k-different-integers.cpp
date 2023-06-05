class Solution {
public:
    int slidingwindow(vector<int>&nums,int k){
        unordered_map<int,int>m;
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)m.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            cout<<ans<<endl;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int val1=slidingwindow(nums,k); //atmost k distinct
       int val2=slidingwindow(nums,k-1); //atmost k-1 distinct
       //val1-val2 exactly k distinct subarray
       return val1-val2;
    }
};