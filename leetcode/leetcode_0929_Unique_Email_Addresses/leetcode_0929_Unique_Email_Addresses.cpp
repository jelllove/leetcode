class Solution {
public:
    
    bool validEmailAddr(string &str, string &localName, string &domainName)
    {
        //Check the @ amount
        size_t pos;
        if (((pos = str.find("@")) == string::npos) ||
            (str.find("@", pos + 1) != string::npos))
            return false;
        
        int i = 0;
        
        localName = "";
        while (i < pos)
        {
            if (str[i] == '+')
                break;
            if (str[i] == '.')
            {
                ++i;
                continue;
            }
            
            if (!isalpha(str[i]))
                return false;
            else if (isupper(str[i]))
                return false;
            else
                localName += str[i];
            
            ++i;
        }
        
        if (localName == "")
            return false;
        
        domainName = "";
        i = pos + 1;
        while (i < str.size())
        {
            if (!isalpha(str[i]) && str[i] != '.')
                return false;
            else if (isupper(str[i]) && str[i] != '.')
                return false;
            else
                domainName += str[i];
            
            ++i;
        }
        
        
        if (domainName == "")
            return false;
        
        else
            return true;
        
    }
    
    int numUniqueEmails(vector<string>& emails) {
        int ans = 0;
        set<string> count_set;
        for (string &str: emails)
        {
            string localName = "";
            string domainName = "";
            if (validEmailAddr(str, localName, domainName))
            {
                count_set.insert(localName + "@" + domainName);
            }
        }
        
        return count_set.size();
    }
};