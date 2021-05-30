class Solution {
public:
    int lengthOfLastWord(string str) {
        //Method 1: Brute force
        int e = -1;
        int s = -1;
        
        for (int i = str.size() - 1; i >= 0; --i)
        {
            if (isalpha(str[i]))
            {
                if (e == -1)
                {
                    e = s = i;
                }
                else
                {
                    s = i;
                }
            }
            else
            {
                if (e != -1)
                    break;
            }
        }
        
        return (e == -1 ? 0 : (e - s + 1));
    }
};