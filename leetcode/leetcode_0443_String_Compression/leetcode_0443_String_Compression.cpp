class Solution {
public:
    
    
    int compress(vector<char>& chars) {
        
        if (chars.size() <= 1)
            return chars.size();
        
        
        int curChar = chars[0];
        int count = 1;
        int idx = 0;
        
        for (int i = 1; i < chars.size(); ++i)
        {
            if (curChar == chars[i])
            {
                ++count;
            }
            else
            {
                chars[idx++] = curChar;
                if (count > 1)
                {
                    string num = to_string(count);
                    for (auto &n : num)
                        chars[idx++] = n;
                }
                    
                
                curChar = chars[i];
                count = 1;
            }
        }
        
        chars[idx++] = curChar;
        if (count > 1)
        {
            string num = to_string(count);
            for (auto &n : num)
                chars[idx++] = n;
        }
        
        
        return idx;
        
    }
};