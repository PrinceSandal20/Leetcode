class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag=n%2;
        n=n/2;
        while(n>0){
            if(flag==n%2)return false;
            flag=n%2;
            n=n/2;
        }
        return true;
    }
};