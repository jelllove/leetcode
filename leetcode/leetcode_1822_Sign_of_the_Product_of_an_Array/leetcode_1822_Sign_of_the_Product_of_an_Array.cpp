class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 0;
        
        //统计负数的个数
        int c = 0;
        for (auto &n : nums)
        {
            if (n == 0)
                return 0;
            if (n < 0)
                ++c;
        }
        
        //如果负数的个数是双数，那最后的积肯定是正的
        return (c % 2 == 0) ? 1 : -1;
    }
};