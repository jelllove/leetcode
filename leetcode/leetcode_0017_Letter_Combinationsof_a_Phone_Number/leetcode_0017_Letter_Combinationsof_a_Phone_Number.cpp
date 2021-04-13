
vector<vector<char>> keyB = 
{
    {'a', 'b', 'c'},      // 2
    {'d', 'e', 'f'},      // 3
    {'g', 'h', 'i'},      // 4
    {'j', 'k', 'l'},      // 5
    {'m', 'n', 'o'},      // 6
    {'p', 'q', 'r', 's'}, // 7
    {'t', 'u', 'v'},      // 8
    {'w', 'x', 'y', 'z'}  // 9
};

class Solution {
public:
    
    //一个递归函数
    void helper(vector<string> &ans, string content, string &digits, int index)
    {
        if (index >= digits.size())
        {
            if (content != "")
                ans.push_back(content);
            return;
        }
        
        //因为那个索引表是从数字2开头的，所以要减2
        int i = digits[index] - '2';
        
        for (int k = 0; k < keyB[i].size(); ++k)
        {
            //把不当前的字符串content上加一个字母，然后调一下个递归
            helper(ans, content + keyB[i][k], digits, index + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        string content = "";
        helper(ans, content, digits, 0);
        
        return ans;
    }
};