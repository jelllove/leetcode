class Solution {
public:
    bool loop(string s, int l, int h)
    {
        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int h = s.size()-1;
        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            else
            {
                /*
                 if they don't match then which one you are going to ignore?
                */
                return (loop(s,l+1,h) || loop(s,l,h-1));       
            }
        }
        return true;
        
    }
};