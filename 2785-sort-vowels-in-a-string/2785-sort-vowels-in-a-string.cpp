class Solution {
    private:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>>minH;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                minH.push(s[i]);
            }
        }
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=minH.top();
                minH.pop();
            }
        }
        return s;
    }
};