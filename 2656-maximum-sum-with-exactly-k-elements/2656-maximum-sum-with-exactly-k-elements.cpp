class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>maxH;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            maxH.push(nums[i]);
        }
        while(!maxH.empty() && k>0){
            int val=maxH.top();
            maxH.pop();
            ans+=val;
            k--;
            maxH.push(val+1);
        } 
        return ans;
    }
};