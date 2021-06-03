class Solution {
public:
    string addBinary(string a, string b) {
        //using the traverse
        
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