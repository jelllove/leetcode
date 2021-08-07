class Solution {
public:
    
    bool validIPv6SubSet(string str)
    {
        if (str.size() == 0 || str.size() > 4)
            return false;
        
        int caseType = 0;
        
        for (auto &c : str)
        {
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
                continue;
            else
                return false;
        }
        
        return true;
    }
    
    bool validIPv4SubSet(string str)
    {
        if (str.size() == 0 || str.size() > 3)
            return false;
        if (str.size() > 1 && str[0] == '0')
            return false;
        
        for (auto &c : str)
        {
            if (c < '0' || c > '9')
                return false;
        }
        return stoi(str) <= 255;
    }
    
    void parseString(string &str, string strTok, vector<string> &res)
    {
        
        if (str.size() > 1 && (str[0] == ':' || str[str.size() - 1] == ':' || str[0] == '.' || str[str.size() - 1] == '.'))
            return;
        
        char *pTok = strtok((char *)str.c_str(), strTok.c_str());
        
        while (pTok != nullptr)
        {
            res.push_back(pTok);
            pTok = strtok(nullptr, strTok.c_str());
        }
    }
    
    int countSymbol(string &str, char c)
    {
        int sum = 0;
        for (auto &s : str)
            if (s == c)
                ++sum;
        
        return sum;
    }
    
    string validIPAddress(string IP) {
        
        vector<string> ans;
        
        if (IP.find(".") != string::npos)
        {   
            if (countSymbol(IP, '.') != 3)
                return "Neither";
            
            parseString(IP, ".", ans);
            if (ans.size() != 4)
                return "Neither";
            
            for (auto &a : ans)
            {
                if (!validIPv4SubSet(a))
                    return "Neither";
            }
            
            return "IPv4";
        }
        else if (IP.find(":") != string::npos)
        {
            if (countSymbol(IP, ':') != 7)
                return "Neither";

            parseString(IP, ":", ans);
            if (ans.size() != 8)
                return "Neither";
            
            for (auto &a : ans)
            {
                if (!validIPv6SubSet(a))
                    return "Neither";
            }
            
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
        
    }
};