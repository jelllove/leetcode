class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        
        
        //Method 1: Using the list
        //-------------------------------------------------------------------------------
        /*
        list<int> l;
        
        while (x > 0)
        {
            l.push_back(x % 10);
            x /= 10;
        }
        
        while (l.size() > 1)
        {
            if (l.front() != l.back())
                return false;
            l.pop_front();
            l.pop_back();
        }
        
        return true;
        */
        
        //Method 2: using the vector + two pointer
        //-------------------------------------------------------------------------------
        /*
        vector<int> v;
        
        while (x > 0)
        {
            v.push_back(x % 10);
            x /= 10;
        }
        
        int l = 0;
        int r = v.size() - 1;
        
        while (l < r)
        {
            if (v[l] != v[r])
                return false;
            ++l;
            --r;
        }
        
        return true;
        */
        
        
        //Method 3: using the string
        //-------------------------------------------------------------------------------
        /*
        string str = to_string(x);
        int l = 0;
        int r = str.size() - 1;
        
        while (l < r)
        {
            if (str[l] != str[r])
                return false;
            ++l;
            --r;
        }
        
        return true;
        */
        
        //Method 4: using the string's reverse
        //-------------------------------------------------------------------------------
        /*
        string str = to_string(x);
        string str2 = str;
        reverse(str2.begin(), str2.end());
        
        return str == str2;
        */
        
        
        //Method 5// reverse the int, and compare them
        //-------------------------------------------------------------------------------
        int m = x;
        int y = 0;
        
        while (m > 0)
        {
            if ((y > (INT_MAX / 10)) || ((y == INT_MAX) && ((INT_MAX % 10) < (m % 10))))
                return false;
            y *= 10;
            y += (m % 10);
            m /= 10;
        }
        
        return y == x;
        
    }
};