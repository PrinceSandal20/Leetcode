class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>vp;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],cost[i]});
            sum+=cost[i];
        }
        sort(vp.begin(),vp.end());
        long long ans=0;
        long long n=(sum+1)/2;
        int val=-1;
        for(int i=0;i<nums.size();i++){
            n-=vp[i].second;
            if(n<=0){
                val=vp[i].first;
                break;
            }
        }
        for(int i=0;i<vp.size();i++){
            ans+=(long long)abs(val-nums[i])*cost[i];
        }
        return ans;
    }
};