//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        long long mode=1e9+7;
        long long ans=0;
        for(int i=31;i>=0;i--){
            long long set=0,unset=0;
            for(int j=0;j<N;j++){
                if(A[j] & 1<<i){
                    set++;
                }
                else{
                    unset++;
                }
            }
            ans=(ans+(set*unset)%mode)%mode;
        }
        return (ans*2)%mode;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends