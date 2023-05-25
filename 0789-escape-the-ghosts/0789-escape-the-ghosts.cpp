class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int pacman=abs(target[0])+abs(target[1]);
        for(int i=0;i<ghosts.size();i++){
            if(abs(target[0]-ghosts[i][0])+abs(target[1]-ghosts[i][1])<=pacman){
                return false;
            }
        }
        return true;
    }
};