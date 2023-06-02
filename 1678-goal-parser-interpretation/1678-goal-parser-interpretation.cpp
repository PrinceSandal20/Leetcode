class Solution {
public:
    string interpret(string command) {
        string ans="";
        for(int i=0;i<command.size();i++){
            if(command[i]=='G'){
                ans+=command[i];
            }
            else if(command[i]=='('){
                string temp="";
                i++;
                while(command[i]!=')' && i<command.size()){
                    temp+=command[i++];
                }
                //i--;
                if(temp==""){
                    ans+='o';
                }
                else{
                    ans+=temp;
                }
            }
        }
        return ans;
    }
};