class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans=-1,i=0,j=0;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m[0]>k){
                m[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};