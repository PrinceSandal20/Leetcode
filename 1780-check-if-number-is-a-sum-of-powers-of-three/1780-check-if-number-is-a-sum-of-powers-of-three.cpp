class Solution {
public:
    bool checkPowersOfThree(int n) {
        int sum=0;
        for(int i=16;i>=0;i--){
            if(sum+pow(3,i)==n)return true;
            else if(sum+pow(3,i)<n)sum=sum+pow(3,i);
        }
        return false;
    }
};