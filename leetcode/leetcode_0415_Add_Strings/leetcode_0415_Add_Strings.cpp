class Solution {
public:
    string addStrings(string num1, string num2) {
        
        if (num1.size() == 0)
            return num2;
        
        if (num2.size() == 0)
            return num1;
        
        string res(max(num1.size(), num2.size()) + 1, '0');
        
        int carry = 0;
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int idx = res.size() - 1;
        while (n1 >= 0 || n2 >= 0 || carry != 0)
        {
            if (n1 >= 0)
            {
                carry += (num1[n1] - '0');
                --n1;
            }
            
            if (n2 >= 0)
            {
                carry += (num2[n2] - '0');
                --n2;
            }
            
            res[idx] = carry % 10 + '0';
            carry /= 10;
            --idx;
        }
        
        return res.substr(idx + 1, res.size() - idx + 1);
        
        
        
    }
}; 