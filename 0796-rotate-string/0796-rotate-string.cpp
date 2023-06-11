class Solution {
public:
    bool rotateString(string s, string goal) {
        int count=0;
        while(count!=s.size()){
            char ch=s[0];
            s.erase(s.begin());
            s.push_back(ch);
            count++;
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};