class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>vp;
        for(int i=0;i<n-1;i++){
            vp.push_back(weights[i]+weights[i+1]);
        }
        sort(vp.begin(),vp.end());
        long long mnsum=0,mxsum=0;
        for(int i=0;i<k-1;i++){
            mnsum+=vp[i];
            mxsum+=vp[n-2-i];
        }
        return mxsum-mnsum;
    }
};