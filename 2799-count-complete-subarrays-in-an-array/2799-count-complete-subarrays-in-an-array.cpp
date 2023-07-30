class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(auto val:nums){
            st.insert(val);
        }
        int ans=0;
        unordered_map<int,int>m;
        int i=0,j=0;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m.size()==st.size()){
                ans+=nums.size()-j;
                m[nums[i]]--;
                if(m[nums[i]]==0)m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};