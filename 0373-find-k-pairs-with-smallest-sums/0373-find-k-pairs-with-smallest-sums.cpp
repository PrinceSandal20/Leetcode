class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,pair<int,int>>> maxH;
        vector<vector<int>> ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                if(maxH.size()<k)
                    maxH.push({sum,{nums1[i],nums2[j]}});
                else if(sum<maxH.top().first)
                {
                    maxH.pop();
                    maxH.push({sum,{nums1[i],nums2[j]}});
                }
                else
                    break;
            }
        }  
        while(maxH.size()>0)
        {
            ans.push_back({maxH.top().second.first,maxH.top().second.second});
            maxH.pop();
        }
        return ans;
    }
};