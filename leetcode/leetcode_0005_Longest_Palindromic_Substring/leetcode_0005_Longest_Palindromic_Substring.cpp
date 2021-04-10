class Solution {
public:
    
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        
        //Method 1:暴力破解，发现行不通，思路应该是对的
        /*
        if (s.size() <= 1)
            return s;
        
        int maxLen = 1;
        int startPos = 0;
        int l = 0;
        
        while (l < s.size() )
        {
            if ((s.size() - l) <= maxLen)
                break;
            
            for (int len = s.size() - l; len >= 1; --len)
            {
                if (isPalindrome(s.substr(l, len)))
                {
                    if (len > maxLen)
                    {
                        maxLen = len;
                        startPos = l;
                    }
                }
            }
            ++l;
        }
        
        return s.substr(startPos, maxLen);
        */
        
        
        
        
        
        //Method 2
        
        if (s.size() <= 1)
            return s;
        
        //生成一个二维数组
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        int len = s.length();
        
        int maxLen = 1; //存放最长的长度
        int startPos = 0;//最长长度的起始位置
        
        int i = 0, j = 0;
        for (i = 0; i < len; i++)
        {
            dp[i][i] = true;//让中间的线都为TRUE
        }
        
        //从下往上
        for (i = len - 1; i >= 0; --i)
        {
            //从中间点往右
            for (j = i + 1; j < len; ++j)
            {
                //如果两位相等
                if (s[i] == s[j])
                {
                    //判断这个数的左下角的格子是否是T，或是过了中线了
                    if ((i+1) > (j -1) || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        if ((j - i + 1) > maxLen)
                        {
                            //记录最大的长度
                            maxLen = (j - i + 1);
                            startPos = i;
                        }
                    }
                }
            }
        }
    
        return s.substr(startPos, maxLen);
        
    }
};