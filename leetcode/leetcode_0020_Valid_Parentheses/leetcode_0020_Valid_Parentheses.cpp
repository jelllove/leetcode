class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (auto item : s)
        {
            switch (item)
            {
                case '(':
                case '{':
                case '[':
                    st.push(item);
                    break;
                    
                case ')':
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else
                        return false;
                    break;
                    
                    
                case '}':
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;
                    
                    
                case ']':
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else
                        return false;
                    break;
                    
            }
        }
        
        return st.empty();
    }
};