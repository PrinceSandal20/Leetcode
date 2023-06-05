class Solution {
public:
    string find(string &a){
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                a[i]='1';
            }
            else{
                a[i]='0';
            }
        }
        reverse(a.begin(),a.end());
        return a;
    }
    char findKthBit(int n, int k) {
        string ds="0";
        int count=1;
        while(count<n){
            ds=ds+"1"+find(ds);
            count++;
        }
        return ds[k-1];
    }
};