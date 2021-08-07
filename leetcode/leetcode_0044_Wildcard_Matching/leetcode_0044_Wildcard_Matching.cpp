class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int matchPos = -1;
        int starPos = -1;
        
        while (i < s.size())
        {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?'))
            {
                ++i;
                ++j;
            }
            else if (j < p.size() && p[j] == '*')
            {
                matchPos = i;
                starPos = j;
                j = starPos + 1;
            }
            else if (starPos != -1)
            {
                ++matchPos;
                i = matchPos;
                j = starPos + 1;
            }
            else
                return false;
        }
        
        while (j < p.size() && p[j] == '*')
            ++j;
        
        return j == p.size();
    }
};