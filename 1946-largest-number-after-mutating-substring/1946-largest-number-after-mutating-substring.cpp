class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        for(int i=0;i<num.size();i++){
            int idx=num[i]-'0';
            if(change[idx]>idx){
                while(change[idx]>=idx){
                    num[i]=change[idx]+'0';
                    i++;
                    idx=num[i]-'0';
                    if(i==num.size()){
                        break;
                    }
                }
                break;
            }
        }
        return num;
    }
};