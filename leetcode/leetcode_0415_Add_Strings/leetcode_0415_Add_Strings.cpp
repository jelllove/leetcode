class Solution {
public:
    string addStrings(string num1, string num2) {
        int pro = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        string ans = "";
        
        while (i >= 0 || j >= 0 || pro > 0)
        {
            int tmp = pro;
            pro = 0;
            
            if (i >= 0)
            {
                tmp += (num1[i] - '0');
                --i;
            }
            
            if (j >= 0)
            {
                tmp += (num2[j] - '0');
                --j;
            }
            
            pro = tmp / 10;
            tmp %= 10;
            
            ans = to_string(tmp) + ans;
        }
        
        return ans;
    }
};