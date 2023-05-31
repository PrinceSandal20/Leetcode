class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int cnt=0,idx=i;
            while(idx){
                if(idx%2!=0){
                    cnt++;
                }
                idx=idx>>1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};