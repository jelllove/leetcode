class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1)
            return true;
        
        int l = 0;
        int r = s.length() - 1;
        
        while (l < r)
        {
            //判断是否为字母或数字
            if (!isalnum(s[l]))
            {
                //如果不是的话，直接跳到一个
                ++l;
                continue;
            }
            
            if (!isalnum(s[r]))
            {
                --r;
                continue;
            }
            
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }
        
        return true;
    }
};