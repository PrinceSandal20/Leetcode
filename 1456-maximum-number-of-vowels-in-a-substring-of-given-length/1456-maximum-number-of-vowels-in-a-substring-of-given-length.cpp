class Solution {
public:
     bool isVowel(char p)
    {
        if(p=='a' || p=='e' || p=='i' || p=='o' || p=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ans=INT_MIN;
        int vowelCount=0;
        while(j<s.length())
        {
            if(isVowel(s[j]))
            {
                vowelCount++;
            }
            if(j-i+1==k)
            {
                ans=max(ans,vowelCount);
                if(isVowel(s[i]))
                {
                    vowelCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};