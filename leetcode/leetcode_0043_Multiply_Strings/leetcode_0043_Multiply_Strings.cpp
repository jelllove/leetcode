class Solution {
public:
    
    
    string multiString(string numMulti, char numSingle)
    {
        int sn = (numSingle - '0');
        
        int pro = 0;
        
        int i = numMulti.size() - 1;
        
        string res = "";
        
        while (i >= 0 || pro != 0)
        {
            int tmp = pro;
            if (i >= 0)
            {
                tmp += (sn * (numMulti[i] - '0'));
                --i;
            }
            
            pro = tmp / 10;
            tmp %= 10;
            
            res = to_string(tmp) + res;
        }
        
        return res;
    }
    
    string addString(string num1, string num2)
    {
        int pro = 0;
        
        string res = "";
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        while (i >= 0 || j >= 0 || pro != 0)
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
            
            res = to_string(tmp) + res;
        }
        return res;
    }
    
    string multiply(string num1, string num2) {
        
        //Method 1: using the brute force, low efficiency.
        /*
        string strSmall = num1.size() > num2.size() ? num2 : num1;
        
        string strBig = num1.size() <= num2.size() ? num2 : num1;
        
        
        string ans = "0";
        
        for (int i = strSmall.size() - 1; i >= 0; --i)
        {
            string tmp = multiString(strBig, strSmall[i]);
            ans = addString(ans, tmp);
            
            strBig += "0";    
        }
        
        for (auto &a : ans)
        {
            if (a != '0')
                return ans;
        }
        
        return "0";
        */
        
        //Method 2: using the math pattern
        if (num1.size() == 0 || num2.size() == 0)
            return "0";
        
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);
        
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        int carry = 0;
        int k = m + n - 1;
        while (k >= 0)
        {
            res[k] += carry;
            carry = res[k] / 10;
            res[k] %= 10;
            --k;
        }
        
        k = 0;
        while (k < (m + n) && res[k] == 0)
            ++k;
        
        string ans = "";
        while (k < (m + n))
        {
            ans += (res[k] + '0');
            ++k;
        }
        
        return (ans == "") ? "0" : ans;
    }
};