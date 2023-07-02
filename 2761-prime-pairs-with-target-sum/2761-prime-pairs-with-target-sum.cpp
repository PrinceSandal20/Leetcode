class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        //sieve of erotnes to find prime no or not  till n;
        vector<bool>prime(n+1,1);
        prime[0]=false,prime[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i])
            {
                for(int j=i*i; j<=n; j+=i)
                    prime[j]=false;
            }
        }
        vector<vector<int>>ans;
        for(int i=1;i<=n/2;i++){
            if(prime[i] && prime[n-i]){
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};