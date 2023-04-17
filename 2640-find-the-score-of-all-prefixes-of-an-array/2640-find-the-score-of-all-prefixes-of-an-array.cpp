class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>conver((long long)nums.size());
        long long mx=0;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,(long long)nums[i]);
            conver[i]=(long long)nums[i]+mx;
            cout<<conver[i]<<endl;
        }
        for(long long i=1;i<conver.size();i++){
            conver[i]=conver[i-1]+conver[i];
        }
        return conver;
    }
};