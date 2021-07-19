class Solution {
public:
    
    bool isDecimal(string s)
    {
        if (s.size() == 0)
            return false;
        
        bool hasDot = false;
        bool hasNum = false;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '-' || s[i] == '+')
            {
                if (i != 0)
                    return false;
                
            }
            else if (s[i] == '.')
            {
                if (hasDot)
                    return false;
                else
                    hasDot = true;
            }
            else if (s[i] < '0' || s[i] > '9')
                return false;
            else
                hasNum = true;
        }
        
        return hasNum;
    }
    
    bool isInteger(string s)
    {
        if (s.size() == 0)
            return false;
        
        bool hasNum =false;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '-' || s[i] == '+')
            {
                if (i != 0)
                    return false;
                
            }
            else if (s[i] < '0' || s[i] > '9')
                return false;
            else
                hasNum = true;
        }
        
        return hasNum;
    }
    
    bool isNumber(string s) {
        
        int e_index = -1;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                if (e_index == -1)
                    e_index = i;
                else
                    return false;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        
        if (e_index == -1)
        {
            return isDecimal(s);
        }
        else
        {
            string left = s.substr(0, e_index);
            string right = s.substr(e_index + 1, s.size() - e_index);
            return isDecimal(left) && isInteger(right);
        }
    }
};