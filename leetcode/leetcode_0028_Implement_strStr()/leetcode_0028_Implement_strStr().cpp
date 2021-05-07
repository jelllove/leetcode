class Solution {
public:
    int strStr(string haystack, string needle) {
        //Method 1: brust force
        //如果相同的话，或是查找串为空的话，直接返回0
        if (haystack == needle || needle == "")
            return 0;
        
        int i = 0;
        //从0开始一个个遍历被查找串，当剩下的串比查找串还小的话，就不要看了
        while (i < haystack.size() && (needle.size() + i) <= haystack.size())
        {
            //如果被查串的第一个字符与被查找串的第一个字符相符合，就遍历一次查找串
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
        
    }
};