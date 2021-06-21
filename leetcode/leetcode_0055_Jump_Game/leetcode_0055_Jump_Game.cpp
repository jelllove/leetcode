class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        //Method 1: using the dp
        //如果只有一个数，那就已经到达终点了
        if (nums.size() == 1)
            return true;
        
        int dp = nums[0];//把第一个值赋值给dp
        if (dp == 0)//如果DP为0，那就是直接走不了了，那直接返回FALSE, 比如[0, 2, 3, 4]
            return false;
        if (dp >= nums.size() - 1) //如果第一步就可以直接跨到了，那直接TRUE, 比如[5, 3, 1, 8]
            return true;
            
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            dp = max(nums[i], dp - 1);//下一步去取新的一步和上一步减1的最大值
            if (dp == 0)//如果算下来是没有好走了，比如[1, 0, 1, 0]
                return false;
            if (dp >= (nums.size() - i - 1)) //如果正好已经可以到达了，比如 [2, 3, 1, 1, 4]中的第二步（3）
                return true;
        }
        
        return false;
        
    }
};