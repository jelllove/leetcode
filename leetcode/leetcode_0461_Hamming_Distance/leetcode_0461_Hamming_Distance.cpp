class Solution {
public:
    //题目的意思是找出两个数字上，以bit为单位的，有多少个位是不同的，返回这个数目就可以了
    int hammingDistance(int x, int y) {
        //Method 1: brute force
        /*
        //先算出所有的位的个数，因为机器不同，所以位也可能不同
        const int BIT_COUNT = sizeof(x) * 8;
        int ans = 0;
        for (int i = 0; i < BIT_COUNT; ++i)
        {
            if ((x & 0x1) != (y & 0x1))
                ++ans;
            x >>= 1;
            y >>= 1;
        }
        
        return ans;
        */
        
        //Method 2: using the bitset
        /*
        const int BIT_COUNT = sizeof(x) * 8;
        
        //x与y进行了异或的操作之后，z的结果就是那个所有不相等的地方都变成了1，相等的地方变成了0
        int z =  x ^ y;
        
        bitset<BIT_COUNT> bt(z);
        
        return bt.count();
        */
        
        //Method 3: using the x &= (x-1)
        
        //x与y进行了异或的操作之后，z的结果就是那个所有不相等的地方都变成了1，相等的地方变成了0
        int z =  x ^ y;
        int ans = 0;
        
        while (z != 0)
        {
            ++ans;
            z &= (z - 1);
        }
        
        return ans;
        
        
    }
};