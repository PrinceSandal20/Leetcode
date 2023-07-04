class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ans;
        for(auto value:m)
        {
            if(value.second!=3)
            {
                ans=value.first;
            }
        }
        return ans;
    }
};