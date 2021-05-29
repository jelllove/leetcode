class Solution {
public:
    int longestValidParentheses(string s) {
        
        //Method 1: change the valid parentheses to "*"
        /*
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
        */
        
        //Method 2: Dynamic Programming
        if (s.size() == 0)
            return 0;
        
        int ans = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ')')
            {//只处理右括号的情况，所以第0个不用去看了，只要从第1个开始就行了
                if (s[i - 1] == '(')
                {//如果前一个是左括号，比如“（）”，那就判断一下是不是第1个，如果是的话当前的DP直接用0+2,否则的话使用dp[i] = dp[i - 2] + 2;
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    //如果前一个不是左括号，那可能就是这样的： (()), i =3,  dp[] = {0, 0, 2, ?}, 也可能是这样"())",这种的话，因为 i - dp[i - 1]会失败，所以不会去判断
                    //那就判断一下
                    //这时要加的话，除了上一个dp[i - 1]，要加，同时也要加2， 还要加上一个个括号，比如"()(())"
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0 ) + 2;
                }
                
                ans = max(ans, dp[i]);
            }
        }
        
        return ans;
    }
};