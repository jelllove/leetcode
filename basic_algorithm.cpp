#include "include/public.h"

class Solution {
public:
    
    bool splitString(string &str, string declime, vector<string> &res)
    {
        char *p = strtok((char *)str.c_str(), declime.c_str());
        
        while (p != nullptr)
        {
            res.push_back(p);
            p = strtok(nullptr, declime.c_str());
        }
        
        return res.size() != 0;
    }
    
    void dfs(vector<string> &res, int &idx)
    {
        if (idx >= res.size())
            return;
        
        if (res[idx] == "#")
            return;
        
        dfs(res, ++idx);
        dfs(res, ++idx);
    }
    
    
    bool isValidSerialization(string preorder) {
        
        vector<string> res;
        if (!splitString(preorder, ",", res) )
            return false;
        
        int idx = 0;
        dfs(res, idx);
        if (idx >= res.size())
            return true;
        else
            return false;
    }
};

int main(int argc, char *argv[])
{

    Solution().isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");

    return EXIT_SUCCESS;
}