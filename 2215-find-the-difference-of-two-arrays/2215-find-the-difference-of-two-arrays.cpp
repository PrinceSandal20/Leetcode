class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v(2);
        set<int> s1,s2;
        for(int i=0;i<nums1.size();i++)
        {
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            s2.insert(nums2[i]);
        }
        for(auto &val : s1)
        {
            if(s2.count(val)==0)
            {
                v[0].push_back(val);
            }
        }
        for(auto &val : s2)
        {
            if(s1.count(val)==0)
            {
                v[1].push_back(val);
            }
        }
        return v;
    }
};