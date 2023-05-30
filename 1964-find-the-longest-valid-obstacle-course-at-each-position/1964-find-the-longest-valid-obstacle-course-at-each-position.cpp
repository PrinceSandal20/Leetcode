class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>res(n,INT_MAX),ans;
        for(int i=0;i<n;i++){
            int idx=upper_bound(res.begin(),res.end(),obstacles[i])-res.begin();
            ans.push_back(idx+1);
            res[idx]=obstacles[i];
        }
        return ans;
    }
};