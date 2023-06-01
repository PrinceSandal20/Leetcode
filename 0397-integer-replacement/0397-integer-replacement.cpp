class Solution {
public:
    int dfs(long long int n){
        if(n==1){
            return 0;
        }
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(n%2==0){
            a=1+dfs(n>>1);
        }
        else{
            b=1+dfs(n+1);
            c=1+dfs(n-1);
        }
        return min({a,b,c});
    }
    int integerReplacement(int n) {
        return dfs(n);
    }
};