class Solution {
public:
    int precedence(char ch){
        if(ch=='+' || ch=='-'){
            return 1;
        }
        else if(ch=='*' || ch=='/'){
            return 2;
        }
        return 0;
    }
    int calculate(string s) {
        stack<char>ope;
        stack<int>operand;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9'){
                int test=0;
                while(i<s.size() && s[i]>='0' && s[i]<='9'){
                    test=test*10+(s[i]-'0');
                    i++;
                }
                i--;
                operand.push(test);
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                while(!ope.empty() && !operand.empty() && precedence(ope.top())>=precedence(s[i])){
                    int val1=operand.top();
                    operand.pop();
                    int val2=operand.top();
                    operand.pop();
                    if(ope.top()=='+'){
                        operand.push(val2+val1);
                        ope.pop();
                    }
                    else if(ope.top()=='-')
                    {
                        operand.push(val2-val1);
                        ope.pop();
                    }
                    else if(ope.top()=='*'){
                        operand.push(val2*val1);
                        ope.pop();
                    }
                    else{
                        operand.push(val2/val1);
                        ope.pop();
                    }
                }
                ope.push(s[i]);
            }
        }
        while(!operand.empty() && !ope.empty()){
            int val1=operand.top();
            operand.pop();
            int val2=operand.top();
            operand.pop();
            if(ope.top()=='+'){
                operand.push(val2+val1);
                ope.pop();
            }
            else if(ope.top()=='-')
            {
                operand.push(val2-val1);
                ope.pop();
            }
            else if(ope.top()=='*'){
                operand.push(val2*val1);
                ope.pop();
            }
            else{
                operand.push(val2/val1);
                ope.pop();
            }
        }
        return operand.top();
    }
};