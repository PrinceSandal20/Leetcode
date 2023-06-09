class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0,j=letters.size()-1,ans=0;
        while(i<=j) {
            int m=i+(j-i)/2;           
            if(target>=letters[m]){
                i=m+1;
            }
            else {
                j=m-1;
                ans=m;
            }
        }
        return letters[ans];
    }
};