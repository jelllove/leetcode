class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r)
        {
            //利用了位操作的一个技巧：
            // a和b要交换的话，可以使用这个
            //  a ^= b
            //  b ^= a;
            //  a ^= b;
            // 完成互换
            s[l] ^= s[r];
            s[r] ^= s[l];
            s[l] ^= s[r];
            
            ++l;
            --r;
        }
        
    }
};