class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        
        string str;
        
        bool isComments = false;
        
        vector<string> ans;
            
        for (int i = 0; i < source.size(); ++i)
        {
            for (int j = 0; j < source[i].size(); ++j)
            {
                if (!isComments && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j + 1] == '/')
                {
                    break;
                }
                else if (!isComments && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j + 1] == '*')
                {
                    isComments = true;
                    ++j;
                }
                else if (isComments && j + 1 < source[i].size() && source[i][j] == '*' && source[i][j + 1] == '/')
                {
                    isComments = false;
                    ++j;
                }
                else if (!isComments)
                {
                    str += source[i][j];
                }
            }
            
            if (!isComments && str.size() > 0)
            {
                ans.push_back(str);
                str = "";
            }
        }
        
        return ans;
    }
};