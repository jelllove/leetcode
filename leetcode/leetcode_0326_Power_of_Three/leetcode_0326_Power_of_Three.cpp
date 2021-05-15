class Solution {
public:
    bool isPowerOfThree(int n) {
        
        //Method 1: using the simple way
        //如果是0或负数，肯定不能是3的X次方
        /*
        if (n <= 0)
            return false;
        else if (n == 1)
            //如果是1的话，肯定就对了
            return true;
        else
        {
            while (n > 1)
            {
                //如果n除3后，取余如果是0，那就是整除了
                if (n % 3 != 0)
                    return false;
                else
                    n /= 3;
            }
            
            return true;
        }
        */
        
        //Method 2: The optimize version of method 1
        /*
        if (n <= 0)
            return false;
        
        while (n % 3 == 0)
            n /= 3;
        
        return (n == 1);
        */
        
        //Method 3: using the recursion
        /*
        if (n <= 0)
            return false;
        else if (n == 1)
            return true;
        else
            return (n % 3 != 0) ? false : isPowerOfThree(n / 3);
        */
        
        //Method 4: using the math way
        //The x's max vale  = 3^19 in an integer.
        int m = pow(3, 19);
        //so, the m mod n shall be 0 as well.
        return (n > 0 && (m % n == 0));
        
    }
};