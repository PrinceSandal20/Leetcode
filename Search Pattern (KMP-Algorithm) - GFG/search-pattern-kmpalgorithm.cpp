//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> pref(string s){
            int n=s.size();
            vector<int>lps(n,0);
            int i=1,j=0;
            while(i<n){
                if(s[i]==s[j]){
                    lps[i]=j+1;
                    i++,j++;
                }
                else{
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            return lps;
        }
        vector <int> search(string pat, string txt)
        {
            vector<int>lps(pat.size());
            lps=pref(pat);
            vector<int>ans;
            int i=0,j=0;
            while(i<txt.size()){
                if(txt[i]==pat[j]){
                    i++,j++;
                }
                else{
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
                if(j==pat.size()){
                    ans.push_back(i-pat.size()+1);
                    //j=0;
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends