class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (dividend == divisor)
            return 1;
        if (divisor == 0)
            return std::numeric_limits<int>::max();
        if (dividend == std::numeric_limits<int>::min() && divisor == -1)
            return std::numeric_limits<int>::max();
        
        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;//如果两个是相同的，利用了异或后就是0
        

        
        long long divd = llabs((long long)dividend);
        long long divs = llabs((long long)divisor);
        
        if (divisor == 1 || divisor == -1)
            return flag * divd;
        
        int ans = 0;
        
        while (divd >= divs)
        {
            long long t = divs, p = 1;
            while (divd >= (t << 1))
            {
                t <<= 1;
                p <<= 1;
            }
            
            ans += p;
            divd -= t;
        }
        
        return flag == 1 ? ans : -ans;
        
    }
};