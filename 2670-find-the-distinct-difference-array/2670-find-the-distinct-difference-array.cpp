class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>pref;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            pref.insert(nums[i]);
            m[nums[i]]--;
            if(m[nums[i]]==0){
                m.erase(nums[i]);
            }
            ans.push_back(pref.size()-m.size());
        }
        return ans;
    }
};