class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        
        //Method 1: using the binary find
        int l = 0;
        int r = x;
        
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            
            if (x / m == m)
                return m;
            else if (x / m > m)
                l = m ;
            else
                r = m;
        }
        
        return l;
    }
};