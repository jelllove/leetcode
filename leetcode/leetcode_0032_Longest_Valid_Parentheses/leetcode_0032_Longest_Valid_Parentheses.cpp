class Solution {
public:
    int longestValidParentheses(string s) {
        
        //Method 1: change the valid parentheses to "*"
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            //遇上左括号就直接入栈
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                //如果是右括号，只处理栈中有左括号的情况
                if (!st.empty() && st.top() == '(')
                {
                    //出栈，同时把当前的位置改成*
                    st.pop();
                    s[i] = '*';
                    bool marked = false;
                    //向往找那个对应的左括，找到，同时是第一次找到，那就改成*，但是也不要停，一直找到非*为止。
                    for (int j = i; j >= 0; --j)
                    {
                        if (s[j] == '(' && !marked)
                        {
                            s[j] = '*';
                            marked = true;
                            ans = max(ans, (i - j + 1));
                        }
                        else if (s[j] == '*')
                        {
                            ans = max(ans, (i - j + 1));
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};