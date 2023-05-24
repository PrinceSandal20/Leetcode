class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long,long long>>vp;
        for(int i=0;i<nums1.size();i++){
            vp.push_back({(long long)nums2[i],(long long)nums1[i]});
        }
        sort(vp.begin(),vp.end());
        long long sum=0;
        long long mx=0;
        long long i=vp.size()-1,j=vp.size()-1;
        priority_queue<long long,vector<long long>,greater<long long>>minH;
        while(j>=0){
           sum=sum+vp[j].second;
           minH.push(vp[j].second);
           if(i-j+1<k){
               j--;
           }
           else if(i-j+1==k){
               mx=max(mx,sum*vp[j].first);
               sum-=minH.top();
               minH.pop();
               i--,j--;
           }
        }
        return mx;
    }
};