class Solution {
    private:
      int countsteps(int num){
          if(num==1)return 0;
          return (num%2==0)?1+countsteps(num/2):1+countsteps(3*num+1);
      }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ans;
        for(int i=lo;i<=hi;i++){
            ans.push_back({countsteps(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};