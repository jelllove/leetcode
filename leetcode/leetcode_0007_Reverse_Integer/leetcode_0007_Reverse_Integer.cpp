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


//Using the long long as the solution
//因为是按顺序去移
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0)
            return num;
        
        string ans;
        
        for (auto &c : num)
        {
            while (k > 0 and 
                   ans.size() != 0 and
                   c < ans.back()
                  )
            {
                ans.pop_back();
                --k;
            }
            
            ans.push_back(c);
        }
        
        while (k > 0 and ans.size() != 0 and ans.front() == '0')
            ans = ans.substr(1, ans.size() - 1);
        
        return ans;
            
    }
};