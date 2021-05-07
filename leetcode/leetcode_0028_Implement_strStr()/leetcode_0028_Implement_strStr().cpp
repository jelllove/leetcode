class Solution {
public:
    
    
    vector<int> getNext(string needle)
    {
        if (needle.size() == 0)
            return vector<int>();
        
        vector<int> next(needle.size(), 0);
        
        next[0] = 0;
        
        for (int q = 1, k = 0; q < needle.size(); ++q)
        {
            while (k > 0 && needle[q] != needle[k])
            {
                k = next[k - 1];
            }
            
            if (needle[q] == needle[k])
                ++k;
            
            next[q] = k;
        }
        
        return next;
    }
    
    
    int strStr(string haystack, string needle) {
        //Method 1: brust force
        /*
        //如果主串和模式串相同的话，或是模式串为空的话，直接返回0
        if (haystack == needle || needle == "")
            return 0;
        
        int i = 0;
        //从0开始一个个遍历主串，当剩下的主串比模式串还小的话，就不要看了
        while (i < haystack.size() && (needle.size() + i) <= haystack.size())
        {
            //如果主串的第一个字符与模式串的第一个字符相符合，就遍历一次模式串
            if (haystack[i] == needle[0])
            {
                bool totalMatch = true;
                for (int j = 1; j < needle.size(); ++j)
                {
                    if (needle[j] != haystack[i + j])
                    {
                        totalMatch = false;
                        break;
                    }
                }
                
                if (totalMatch)
                    return i;
            }
            ++i;
        }
        
        return -1;
        */
        
        //Method 2: Using KMP algorithm
        if (haystack == needle || needle == "")
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        
        vector<int> next = getNext(needle);
        
        int i = 0;
        int j = 0;
        
        while (i < haystack.size() && j < needle.size())
        {
            if (haystack[i] == needle[j])
            {
                if (j == needle.size() - 1)
                    return (i - needle.size() + 1);
                ++j;
                ++i;
            }
            else
            {
                if (j > 0)
                    j = next[j - 1];
                else
                    ++i;
            }
        }
        
        return -1;
        
    }
};