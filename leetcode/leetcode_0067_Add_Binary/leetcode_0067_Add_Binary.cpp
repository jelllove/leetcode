class Solution {
public:
    string addBinary(string a, string b) {
        
        //Method 1: using the bit set, it shall work, but throw overflow
        /*
        bitset<1001> bt1(a);
        bitset<1001> bt2(b);
        unsigned long long l = bt1.to_ullong() + bt2.to_ullong();
        
        string ret = "";
        
        while (l != 0)
        {
            if (l & 0x1)
                ret = "1"s + ret;
            else
                ret = "0"s + ret;
            
            l >>= 1;
        }
        
        return ret == "" ? "0" : ret;
        */
        
        //Method 2: using the string to add the string
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        int pro = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || pro != 0)
        {
            int tmp = pro;
            pro = 0;
            
            if (i >= 0)
            {
                tmp += (a[i] - '0');
                --i;
            }
            
            if (j >= 0)
            {
                tmp += (b[j] - '0');
                --j;
            }
            
            pro = tmp / 2;
            tmp %= 2;
            
            ans = to_string(tmp) + ans;
        }
        
        return ans;
        
        
    }
};