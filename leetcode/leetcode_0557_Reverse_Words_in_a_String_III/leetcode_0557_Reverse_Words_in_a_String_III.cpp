class Solution {
public:
    string reverseWords(string s) {
        
        istringstream iss(s);
        
        string ans = "";
        string strTmp;
        while(iss >> strTmp)
        {
            if (ans != "")
                ans += " ";
            
            reverse(strTmp.begin(), strTmp.end());
            ans += strTmp;
            
        }
        
        return ans;
    }
};