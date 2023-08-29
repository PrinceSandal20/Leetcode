class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int>yes,no;
        yes.push_back(0);
        no.push_back(0);
        int count=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N'){
                count++;
            }
            no.push_back(count);
        }
        count=0;
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i]=='Y'){
                count++;
            }
            yes.push_back(count);
        }
        reverse(yes.begin(),yes.end());
        int ans=INT_MAX;
        int idx;
        for(int i=0;i<customers.size()+1;i++){
            if(ans>yes[i]+no[i]){
                ans=yes[i]+no[i];
                idx=i;
            }
        }
        return idx;
    }
};