class Solution {
public:
    
    void parseString(string &str, string symbol, vector<string> &ret)
    {
        char *p = strtok((char *)str.c_str(), symbol.c_str());
        
        while (p != nullptr)
        {
            ret.push_back(p);
            p = strtok(nullptr, symbol.c_str());
        }
    }
    
    int compareVersion(string version1, string version2) {
        vector<string> ret1;
        vector<string> ret2;
        
        
        parseString(version1, ".", ret1);
        parseString(version2, ".", ret2);
        
        int idx1 = 0;
        int idx2 = 0;
        
        while (idx1 < ret1.size() || idx2 < ret2.size())
        {
            if (idx1 == ret1.size())
            {
                if (stoi(ret2[idx2]) > 0)
                    return -1;
                else
                    ++idx2;
            }
            else if (idx2 == ret2.size())
            {
                if (stoi(ret1[idx1]) > 0)
                    return 1;
                else
                    ++idx1;
            }
            else
            {
                if (stoi(ret2[idx2]) > stoi(ret1[idx1]))
                    return -1;
                else if (stoi(ret2[idx2]) < stoi(ret1[idx1]))
                    return 1;
                
                ++idx1;
                ++idx2;
            }
        }
        
        return 0;
        
    }
};