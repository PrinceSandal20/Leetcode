class Solution {
public:
    int find(int start,int target){
        if(start>=target){
            return start-target;
        }
        int a=INT_MAX,b=INT_MAX;
        if(target%2==0){
            a=1+find(start,target>>1);
        }
        else{
            b=1+find(start,target+1);
        }
        return min(a,b);
    }
    int brokenCalc(int startValue, int target) {
        return find(startValue,target);
    }
};