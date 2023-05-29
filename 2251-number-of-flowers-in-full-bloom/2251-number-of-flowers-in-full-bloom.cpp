class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        //sweep line algo
        map<int,int>m;
        int n=people.size();
        for(auto val:people){
            m[val]=0;
        }
        for(auto val:flowers){
            m[val[0]]++;
            m[val[1]+1]--;
        }
        int prefsum=0;
        for(auto &val:m){
            prefsum+=val.second;
            val.second=prefsum;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=m[people[i]];
        }
        return ans;
    }
};