class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0,previdx=-1,count=0,res=0;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1 && previdx==-1){
                previdx=i;
            }
            else if(seats[i]==1 && previdx!=-1)
            {
                ans=max(ans,(i-previdx)/2);
                previdx=i;
            }
        }
        int cnt1=0,cnt2=0;
        if(seats[0]==0){
            for(auto val:seats){
                if(val==0){
                    cnt1++;
                }
                else{
                    break;
                }
            }
        }
        if(seats[seats.size()-1]==0){
            for(int i=seats.size()-1;i>=0;i--){
                if(seats[i]==0){
                    cnt2++;
                }
                else{
                   break;
                }
            }
        }
        return ans==0?max(cnt1,cnt2):max(ans,max(cnt1,cnt2));
    }
};