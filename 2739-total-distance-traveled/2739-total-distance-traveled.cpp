class Solution {
public:
    int distanceTraveled(int m, int a) {
        int count=0;
        int n=m;
        while(n>=5 && a>0){
            n=n-5+1;
            a-=1;
            count++;
        }
        return (m+count)*10;
    }
};