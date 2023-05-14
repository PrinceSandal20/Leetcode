class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(auto val:derived){
            ans=ans^val;
        }
        if(ans==0)return true;
        return false;
    }
};