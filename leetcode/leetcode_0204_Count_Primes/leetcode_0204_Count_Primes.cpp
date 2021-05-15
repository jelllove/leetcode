class Solution {
public:
    int countPrimes(int n) {
        //Method 1: brust force
        /*
        //最普世的想法，但是也是最慢的
        if (n <= 1)
            return 0;
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            bool existent = false;
            for (int k = 2; k < i; ++k)
            {
                if (i % k == 0)
                {
                    existent = true;
                    break;
                }
            }
            
            if (!existent)
                ++ans;
        }
        
        return ans;
        */
        
        //Method 2: using a array to store the found non-prime
        if (n <= 2)
            return 0;
        
        vector<bool> isPrime(n, true);
        
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (!isPrime[i])
                continue;
            
            ++ans;
            
            for (int j = 2; i * j < n; ++j)
            {
                //num i * j  ->
                //example, i = 2, n = 10, j = 2~4;
                isPrime[i * j] = false;
            }
        }
        
        return ans;
    }
};