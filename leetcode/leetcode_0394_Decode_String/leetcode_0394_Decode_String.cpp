class Solution {
public:
    string decodeString(string s) {
        stack<string> myStack;
        
        string strRet = "";
        string strNumer = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                strNumer += s[i];
            }
            else if (s[i] == '[')
            {
                strNumer += s[i];
                myStack.push(strNumer);
                
                strNumer = "";
            }
            else if (s[i] == ']')
            {
                string str = "";
                while (!myStack.empty())
                {
                    string curTop = myStack.top();
                    myStack.pop();
                    
                    if (curTop.find('[') == string::npos)
                    {
                        curTop += str;
                        str = curTop;
                    }
                    else
                    {
                        int times = atoi(curTop.c_str());
                        string strTmp = "";
                        for (int i = 0; i < times; i++)
                        {
                            strTmp += str;
                        }
                        
                        if (myStack.empty())
                        {
                            strRet += strTmp;
                        }
                        else
                        {
                            myStack.push(strTmp);
                        }
                        
                        break;
                    }
                }
                
            }
            else
            {
                if (myStack.empty())
                {
                    strRet += s[i];
                }
                else
                {
                    if (myStack.top().find('[') == string::npos)
                    {
                        myStack.top() += s[i];
                    }
                    else
                    {
                        string str  = "";
                        str += s[i];
                        myStack.push(str);
                    }
                }
            }
        }
        
        return strRet;
    }
};