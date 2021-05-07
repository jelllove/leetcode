class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //这个题目如果理解成最长子串匹配的话，就难了
        string ans = ""; //存放最后的返回值的
        bool success = true;
        //因为是共同的最长前辍，所以可以取任何一个字符串作为base进行比较，所以我们选第一个
        for (int k = 0; k < strs[0].size(); ++k)
        {
            success = true;
            //判断其他的字符串是否在长度上和字符内容上符合要求
            for (int i = 1; i < strs.size(); ++i)
            {
                if (k >= strs[i].size() || strs[i][k] != strs[0][k])
                {
                    success = false;
                    break;
                }
                    
            }
            //如果符合要求就加上去，或者就直接结束了
            if (success)
                ans += strs[0][k];
            else
                break;
        }
        
        return ans;
        
    }
};