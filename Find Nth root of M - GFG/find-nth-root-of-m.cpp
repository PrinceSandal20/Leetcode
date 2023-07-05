//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int i=1,j=m;
	    while(i<=j){
	        int mid=i+(j-i)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)<m){
	            i=mid+1;
	        }
	        else{
	            j=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends