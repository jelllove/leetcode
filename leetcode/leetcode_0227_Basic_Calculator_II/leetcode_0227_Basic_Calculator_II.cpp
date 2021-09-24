class Solution {
public:
    bool presideceOrder(char& op1, char& op2){
        //return true if presidence of op1 > op2
        if(op1 == op2) return false;
        
        if(op1 == '/' and op2 != '*') return true;
        if(op1 == '*' and op2 != '/') return true;
        if(op2 == '/' or op2 == '*') return false;
        
        if(op1 == '+' or op1 == '-') return false;
        return true;
    }
    bool isOperator(char& c){
        if(c == '+' or c == '-' or c == '/' or c == '*') return true;
        return false;
    }
    int solve(int a, int b, char op){
        if(op == '+') return a+b;
        if(op == '-') return a-b;
        if(op == '*') return a*b;
        return a/b;
    }
    int calculate(string s) {
        stack<char> opStack;
        stack<int> stk;
        int index = 0;
        while(index < s.size()){
            if(s[index] != ' '){
                if(isOperator(s[index])){
                    while(!opStack.empty() and !presideceOrder(s[index], opStack.top())){
                        char op2 = opStack.top();
                        opStack.pop();
                        int x = stk.top(); stk.pop();
                        int y = stk.top(); stk.pop();
                        int eval = solve(y, x, op2);
                        stk.push(eval);
                    }
                    opStack.push(s[index]);
                    index++;
                }
                else{
                    string num = "";
                    while(index<s.size() and !isOperator(s[index]) and s[index] != ' '){
                        num += s[index];
                        index++;
                    }
                    int temp = stoi(num);
                    stk.push(temp);
                }
            }
            else index++;
        }
        while(!opStack.empty()){
            char op = opStack.top();
            opStack.pop();
            int x = stk.top(); stk.pop();
            int y = stk.top(); stk.pop();
            int eval = solve(y, x, op);
            stk.push(eval);
        }
        if(stk.empty()) return 0;
        return stk.top();
    }
};