class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        for(auto val:m)
        {
            minH.push({val.second,val.first});
            if(minH.size()>k)
            {
                minH.pop();
            }
        }
        vector<int> ans;
        while(minH.size()>0)
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};