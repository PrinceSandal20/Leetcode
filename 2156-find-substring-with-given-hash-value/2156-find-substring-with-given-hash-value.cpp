class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long p=1;
        for(int i=1;i<k;++i)
            p=(power*p)%modulo;
        long long hash=0;
        int i=s.size()-1,j=s.size()-1;
        int idx=0;
        while(j>=0){
            hash=(hash*power+s[j]-'a'+1)%modulo;
            if(i-j+1==k){
                if(hash==hashValue){
                    idx=j;
                }
                hash=((hash-(s[i]-'a'+1)*p)%modulo+modulo)%modulo;
                i--;
            }
            j--;
        }
        return s.substr(idx,k);
    }
};