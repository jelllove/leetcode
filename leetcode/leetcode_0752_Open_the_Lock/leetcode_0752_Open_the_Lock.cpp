class Solution {

string plusOne(string str, int idx)
{
    if (idx < 0 || idx >= str.size())
        return "";
    
    if (str[idx] == '9')
        str[idx] = '0';
    else
        ++str[idx];
    
    return str;
}
    
string minusOne(string str, int idx)
{
    if (idx < 0 || idx >= str.size())
        return "";
    
    if (str[idx] == '0')
        str[idx] = '9';
    else
        --str[idx];
    
    return str;
}
    
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        
        string str = "0000";
        
        int steps = 0;
        queue<string> q;
        q.push(str);
        
        while (!q.empty())
        {
            int n = q.size();
            
            for (int i = 0; i < n; ++i)
            {
                string topStr = q.front();
                q.pop();
                
                if (topStr == target)
                {
                    return steps;
                }
                else if (deadSet.count(topStr) > 0 || visited.count(topStr) > 0)
                {
                    continue;
                }
                else
                {
                    visited.insert(topStr);
                    for (int k = 0; k < 4; ++k)
                    {
                        string strPlus = plusOne(topStr, k);
                        string strMinus = minusOne(topStr, k);
                        
                        if (deadSet.count(strPlus) == 0 && visited.count(strPlus) == 0)
                            q.push(strPlus);
                        
                        if (deadSet.count(strMinus) == 0 && visited.count(strMinus) == 0)
                            q.push(strMinus);
                    }
                }
                
            }
            ++steps;
        }
        
        return -1;
    }
};