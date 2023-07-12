//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int mode=1e9+7;
    long long int  countPS(string s)
    {
       int n=s.size();
        vector<vector<long long int>>dp(n,vector<long long int>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                if(len==1){
                    dp[i][j]=1;
                }
                else if(len==2){
                    if(s[i]==s[j]){
                        dp[i][j]=3;
                    }
                    else{
                        dp[i][j]=2;
                    }
                }
                else if(s[i]==s[j]){
                    dp[i][j]=1+dp[i+1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                }
                dp[i][j]+=mode;
                dp[i][j]%=mode;
            }
        }
        return dp[0][n-1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends