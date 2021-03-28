class Solution {
public:
    /*
    //Method 1:
    int reverse(int x) {
        int ans = 0;
        int symbol = 1;
        if (x == 0)
            return 0;
        else if (x < 0)
            symbol = -1;
        x = abs(x);
        while (x != 0)
        {
            int n = x % 10;
            x /= 10;
            
            if (symbol == 1)
            {
                if ((ans > (INT_MAX/10)) ||
                    ((ans == INT_MAX / 10) && (n >= INT_MAX % 10)))
                {
                    return 0;
                }
            }
            else
            {
                if ((ans > ((unsigned)INT_MIN/10)) ||
                    ((ans == (unsigned)INT_MIN / 10) && (n >= (unsigned)INT_MIN % 10)))
                {
                    return 0;
                }
            }
            
            ans *= 10;
            ans += n;
        }
        
        return ans * symbol;
        
    }
    */
    //Method 2
    int reverse(int x) {
        int ans = 0;
        int symbol = 1;
        if (x == 0)
            return 0;
        else if (x < 0)
            symbol = -1;
        
        while (x != 0)
        {
            int n = x % 10;
            x /= 10;
            
            if (symbol == 1)
            {
                
                if ((ans > (INT_MAX/10)) ||
                    ((ans == INT_MAX / 10) && (n >= INT_MAX % 10)))
                {
                    return 0;
                }
                ans *= 10;
                ans += n;
            }
            else
            {
                
                if ((ans > ((unsigned)INT_MIN/10)) ||
                    ((ans == (unsigned)INT_MIN / 10) && (-n >= (unsigned)INT_MIN % 10)))
                {
                    return 0;
                }
                ans *= 10;
                ans += -n;
            }
            
        }
        
        return ans * symbol;
    }
};