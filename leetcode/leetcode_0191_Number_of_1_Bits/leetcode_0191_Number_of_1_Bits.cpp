class Solution {
public:
    int hammingWeight(uint32_t n) {

        //这个是利用了bit位中的一个特点
        // n &= (n-1) 的操作后，可以消除掉最后一个1，
        //比如:   n = 000100100,
        //   n - 1  = 000100011
        //      n & (n - 1) = 000100000
        //Method 1: using the n &= (n - 1);
        /*
        int c = 0;
        
        while (n != 0)
        {
            ++c;
            n &= (n - 1);
        }
        return c;
        */
        
        //Method 2: Move the bits
        int c = 0;
        while (n > 0)
        {
            if (n & 0x1)
            {
                ++c;
            }
            n >>= 1;
        }
        return c;
    }
};