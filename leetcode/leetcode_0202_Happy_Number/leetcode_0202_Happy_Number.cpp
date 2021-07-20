class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        
        //Method 1: using the brute force
        unordered_set<int> dupNum;//Store the duplicated num, in case the loop
        
        while (n >= 10)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += pow((n % 10), 2);
                n /= 10;
            }
            
            if (dupNum.count(sum) > 0)
                return false;
            
            
            dupNum.insert(sum);
            n = sum;
        }
        
        return (n == 1 || n == 7);
    }
};