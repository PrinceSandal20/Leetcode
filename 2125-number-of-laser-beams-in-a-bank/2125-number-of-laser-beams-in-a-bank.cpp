class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,prevprod=-1;
        for(int i=0;i<bank.size();i++){
            int laser=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    laser++;
                }
            }
            if(laser && prevprod==-1){
                prevprod=laser;
            }
            else if(laser && prevprod!=-1){
                prevprod=prevprod*laser;
                ans+=prevprod;
                prevprod=laser;
            }
        }
        return ans;
    }
};