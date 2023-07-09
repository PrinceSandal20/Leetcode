class Solution {
public:
    int largestVariance(string s) {
        int ans=INT_MIN;
        vector<int>freq(26,0);
        for(auto val:s){
            freq[val-'a']++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(freq[ch1-'a']>0 && freq[ch2-'a']>0 && ch1!=ch2){
                    int sum=0;
                    int a=0,b=0;
                    for(auto val:s){
                        if(val==ch1){
                            a++;
                        }
                        else if(val==ch2){
                            b++;
                        }
                        else continue;
                        if(b>0){
                            sum=max(sum,a-b);
                        }
                        else if(b==0){
                            sum=max(sum,a-1);
                        }
                        if(a<b){
                            a=b=0;
                        }
                    }
                    ans=max(ans,sum);
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};