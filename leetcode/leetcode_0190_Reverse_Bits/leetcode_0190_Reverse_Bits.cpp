class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //Method 1: using bitset
        /*
        //利用了string进行反转，反转后再转成long
        bitset<32> bt(n);
        string str = bt.to_string();
        reverse(str.begin(), str.end());
        bt = bitset<32>(str);
        return bt.to_ulong();
        */
        
        //Method 2: using the bit
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            ans <<= 1;
            
            if (n & 0x1)
            {    
                ans |= 0x1;
            }
            n >>= 1;
        }
        
        return ans;
    }
};