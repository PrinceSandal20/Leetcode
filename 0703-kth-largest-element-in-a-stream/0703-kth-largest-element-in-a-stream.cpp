class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minH;
    int ans;
    KthLargest(int k, vector<int>& nums) {
        ans=k;
        for(int i=0;i<nums.size();i++)
            minH.push(nums[i]);
        while(minH.size()>k)
            minH.pop();
    }
    
    int add(int val) {
        minH.push(val);
            if(minH.size()>ans)
                minH.pop();
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */