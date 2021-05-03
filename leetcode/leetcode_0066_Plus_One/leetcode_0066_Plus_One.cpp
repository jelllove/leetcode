class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        //Method 1: 按原来它的顺序来计算
        /*
        int p = 1;
        int i = digits.size() - 1;
        while (p > 0 && i >= 0)
        {
            digits[i] += p;
            p = digits[i] / 10;
            digits[i] %= 10;
            
            --i;
            if (p <= 0)
            {
                break;
            }
        }
        
        if (p > 0)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
        */
        
        
        //Method 2: 先反转，然后按新的顺序来计算
        
        reverse(digits.begin(), digits.end());
        int p = 1;
        int i = 0;
        while (p > 0 && i < digits.size())
        {
            digits[i] += p;
            p = digits[i] / 10;
            digits[i] %= 10;
            
            ++i;
            if (p <= 0)
                break;
        }
        
        if (p > 0)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
        
        
    }
};