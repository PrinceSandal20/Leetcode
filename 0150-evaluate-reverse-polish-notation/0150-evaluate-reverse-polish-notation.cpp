class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>operand;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=="+" || s[i]=="-" || s[i]=="*" || s[i]=="/"){
                int val1=operand.top();
                operand.pop();
                int val2=operand.top();
                operand.pop();
                if(s[i]=="+"){
                    operand.push(val2+val1);
                }
                else if(s[i]=="-")
                {
                    operand.push(val2-val1);
                }
                else if(s[i]=="*"){
                    operand.push(val2*val1);
                }
                else if(s[i]=="/"){
                    operand.push(val2/val1);
                }
            }
            else{
                operand.push(stoi(s[i]));
            }
        }
        return operand.top();
    }
};