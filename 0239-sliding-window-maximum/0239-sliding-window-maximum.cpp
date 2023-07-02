class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        while(j<nums.size())
        {
            pq.push({nums[j],j});
           if(j-i+1<k)
           j++;
           else if(j-i+1==k)
           {
               while(pq.top().second<i)
               pq.pop();
               ans.push_back(pq.top().first);
               i++;
               j++;
           }
        }
        return ans;
    }
};