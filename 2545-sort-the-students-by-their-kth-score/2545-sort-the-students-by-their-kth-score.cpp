class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        priority_queue<pair<int,vector<int>>>maxH;
        for(int i=0;i<score.size();i++){
            maxH.push({score[i][k],score[i]});
        }
        vector<vector<int>>ans;
        while(!maxH.empty()){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};