class Solution {
public:
    string minWindow(string s, string t) {
        
        //Method 1, using two array to manage them, but low efficiency
        /*
        if (t.size() > s.size())
            return "";
        if (t.size() == s.size() && t == s)
            return s;
        
        int patternT[256] = {0};//Role model to compare
        int patternS[256] = {0};//dynamomic model to change 
        
        
        string ret = "";
        
        //initial the string t's pattern
        for (auto &letter : t)
        {
            patternT[letter]++;
        }
        
        int left = -1;
        int right = 0;
        
        while (right < s.size())
        {
            //check whether this char is also belong to the string(t)
            if (patternT[s[right]] != 0)
            {
                //if it is first time to assign the value to variable left
                if (left == -1)
                    left = right;
                
                //Record the new find of string(s)
                patternS[s[right]]++;
                
                //if it is not the first left, and current the patternS has reached the patterT's requirement
                if (right != left)
                {
                    for (int k = left; k < s.size(); ++k)
                    {
                        if (patternT[s[k]] == 0)
                        {
                            continue;
                        }
                        else
                        {
                            if (patternT[s[k]] < patternS[s[k]])
                            {
                                patternS[s[k]]--;
                            }
                            else
                            {
                                left = k;
                                break;
                            }
                        }
                        
                    }
                }
                
                bool match = true;
                
                for (int k = 0; k < 256; ++k)
                {
                    if (patternT[k] && patternS[k] < patternT[k])
                    {
                        match = false;
                        break;
                    }
                }
                
                if (match)
                {
                    if (ret == "")
                        ret = s.substr(left, right - left + 1);
                    else if (s.substr(left, right - left + 1).size() < ret.size())
                        ret = s.substr(left, right - left + 1);
                }
                
            }
            
            ++right;
        }
        
        return ret;
        */
        
        
        //Method 2: using the slide window via the unordered_map;
        
        //char + count
        unordered_map<char, int> patternS;
        unordered_map<char, int> patternT;
        
        for (auto &elem : t)
            patternT[elem]++;
        
        int l = 0;
        int len = std::numeric_limits<int>::max();
        
        int amount = patternT.size();
        int got = 0;
        
        string ret = "";
        
        for (int r = 0; r < s.size(); ++r)
        {
            if (patternT[s[r]] > 0)
            {
                patternS[s[r]]++;
                
                if (patternS[s[r]] == patternT[s[r]])
                    ++got;
                
                while (got == amount)
                {
                    if ((r - l + 1) < len)
                    {
                        ret = s.substr(l, r - l + 1);
                        len = ret.size();
                    }
                    
                    if (patternS[s[l]] > 0)
                    {
                        if (patternS[s[l]] == patternT[s[l]])
                            --got;
                        patternS[s[l]]--;
                    }   
                    ++l;
                }
            }
        }
        
        return ret;
        
    }
};