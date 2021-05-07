class Solution {
public:
    string countAndSay(int n) {
        //Method 1: Using the no-recursion
        /*
        //在不使用递归的方法的情况下，其实就是从1开始，一次次的变化当前的字符串
        //然后下一次利用上一次的字符串进行比较得到
        string str = "1";
        for (int i = 1; i < n; ++i)
        {
            string strTmp = "";
            int count = 1;
            char ch = str[0];
            for (int k = 1; k < str.size(); ++k)
            {
                if (ch == str[k])
                {
                    ++count;
                }
                else
                {
                    strTmp += to_string(count);
                    strTmp += ch;
                    count = 1;
                    ch = str[k];
                }
            }
            strTmp += to_string(count);
            strTmp += ch;
            str = strTmp;
        }
        
        return str;
        */
        
        //Method 2: using the recursion
        if (n == 1)
            return "1";
        
        string ret = countAndSay(n - 1);
        string ans = "";
        
        int cnt = 1;
        char ch = ret[0];
        for (int i = 1; i < ret.size(); ++i)
        {
            if (ret[i] == ch)
            {
                ++cnt;
            }
            else
            {
                ans += to_string(cnt) + ch;
                ch = ret[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + ch;
        
        return ans;
        
    }
};