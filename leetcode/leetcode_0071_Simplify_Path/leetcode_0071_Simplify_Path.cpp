
class Solution {
public:
    string simplifyPath(string path) {
        
        //Method 1: using the stack to store all the path
        /*
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
        */
        
        //Method 2, using the deque and the istringstream
        deque<string> deq;
        stringstream ss(path);
        
        string word;
        while (getline(ss, word, '/'))
        {
            if (word.size() != 0)
            {
                if (word == "..")
                {
                    if (deq.size() > 0)
                        deq.pop_back();
                }
                else if (word != ".")
                {
                    deq.push_back(word);
                }
            }
        }
        
        
        string ret = "";
        while (!deq.empty())
        {
            ret += "/"s + deq.front();
            deq.pop_front();
        }
        
        return (ret.size() == 0) ? "/" : ret;
        
        
    }
};