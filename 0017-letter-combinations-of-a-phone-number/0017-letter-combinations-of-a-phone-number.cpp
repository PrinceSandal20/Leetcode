class Solution {
public:
    void findans(int i,vector<string> &v,string &s,string &digits,map<int,string> &m)
    {
        if(i==digits.size())
        {
            v.push_back(s);
        }
        string x=m[digits[i]-'0'];
        for(int j=0;j<x.size();j++)
        {
            s.push_back(x[j]);
            findans(i+1,v,s,digits,m);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string> v;
        string s;
        findans(0,v,s,digits,m);
        return v;
    }
};