class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0 || path[0] != '/')
            return "";
        
        //Method 1: using the stack to store all the 
        stack<string> st;
        st.push("/");
        char *p = strtok((char *)path.c_str() + 1, "/");
        while (p != nullptr)
        {
            if (strcmp(p, "") != 0 && strcmp(p, ".") != 0)
            {
                if (strcmp(p, "..") == 0)
                {
                    if (st.size() > 1)
                        st.pop();
                }
                else
                {
                    st.push(p);
                }
            }
            
            p = strtok(nullptr, "/");
        }
        
        string ans = "";
        while (st.size() > 1)
        {
            if (ans != "")
                ans = "/"s + ans;
            ans = st.top() + ans;
            st.pop();
        }

        ans = "/"s + ans;
        
        return ans;
    }
};