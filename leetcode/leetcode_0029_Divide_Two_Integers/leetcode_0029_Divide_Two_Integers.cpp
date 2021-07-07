class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)  //如果除数是0，就返回0
            return 0;
        if (dividend == divisor) //如果两数相同，直接返回
            return 1;
        if (divisor == 0) //如果被除数是0，原则上是要抛异常的，直接返回最大值
            return std::numeric_limits<int>::max();
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) //如果是最小的INT除-1,应该要返回最大的INT
            return std::numeric_limits<int>::max();
        
        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;//如果两个是相同的，利用了异或后就是0
        
        long long divd = llabs((long long)dividend); //转成LONG LONG 
        long long divs = llabs((long long)divisor);
        
        if (divisor == 1 || divisor == -1)  //如果发现在除数是1 或-1,直接返回就可以了
            return flag * divd;
        
        int ans = 0;  //答案
        
        while (divd >= divs)  //当前被除数还大于当前除数就进入
        {
            long long t = divs, p = 1;//t是用来临时当除数的，p是用来计数的，计有多个t
            while (divd >= (t << 1))//当t翻一倍的时候还小于当前的除数的话，就进入
            {
                t <<= 1; //让t翻一倍
                p <<= 1; //然后p的个数也翻一倍
            }
            
            ans += p; //最后的答案加上几个t
            divd -= t; //被除数减少
        }
        
        return flag == 1 ? ans : -ans;
        
    }
};