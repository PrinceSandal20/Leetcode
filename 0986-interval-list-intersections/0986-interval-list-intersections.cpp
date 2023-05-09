class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<l1.size() && j<l2.size()){
            if(l1[i][1]<l2[j][1]){
                if(l1[i][1]>=l2[j][0]){
                    ans.push_back({max(l1[i][0],l2[j][0]),l1[i][1]});
                }
                i++;
            }
            else{
                if(l1[i][0]<=l2[j][1]){
                    ans.push_back({max(l1[i][0],l2[j][0]),l2[j][1]});
                }
                j++;
            }
        }
        return ans;
    }
};