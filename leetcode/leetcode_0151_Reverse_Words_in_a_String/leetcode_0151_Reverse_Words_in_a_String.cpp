class Solution {
public:
    string reverseWords(string s) {
        
        //Method 1: split the words, and reverse direction insert the word.
        //with C language method
        /*
        string res = "";
        
        char *wordPtr = strtok((char *)s.c_str(), " ");
        while (wordPtr)
        {
            if (res == "")
            {
                res = wordPtr;
            }
            else
            {
                
                res.insert(0, " ");
                res.insert(0, wordPtr);
            }
            
            wordPtr = strtok(NULL, " ");
        }
        
        return res;
        */
        
        
        //Method 2: Twice reverse(big string reverse and single word reverse)
        if (s.size() <= 1)
            return s;
        
        reverse(s.begin(), s.end());
        
        istringstream is(s);
        
        string ans = "";
        string strTmp;
        while (is >> strTmp)
        {
            if (ans != "")
                ans += " ";
            reverse(strTmp.begin(), strTmp.end());
            ans += strTmp;
        }
        
        return ans;
        
        
        //Method 3: splite the words into small word
        //using the C++ method
        /*
        if (s.size() <= 1)
            return s;
        
        istringstream is(s);
        
        string ans = "";
        string strTmp;
        while (is >> strTmp)
        {
            if (ans != "")
                ans.insert(0, " ");
            
            ans.insert(0, strTmp);
        }
        
        return ans;
    
        */
    }
};