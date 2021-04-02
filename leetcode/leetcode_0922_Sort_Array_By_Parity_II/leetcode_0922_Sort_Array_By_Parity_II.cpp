class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        //Method 1:生成一个和原来一样大的数组，然后用两个指针一个去指向
        if (nums.size() <= 1)
            return nums;
        
        
        int oddIndex = 1;
        int evenIndex = 0;
        
        //生成一个和nums一样大的数组
        vector<int> ans(nums.size(), 0);
        
        
        for (auto &n : nums)
        {
            if ((n & 0x01) == 0x01)
            {
                ans[oddIndex] = n;
                oddIndex += 2;
            }
            else
            {
                ans[evenIndex] = n;
                evenIndex += 2;
            }
        }
        
        return ans;
        
        //Method 2:在不使用临时数组的情况下，直接改变nums中的顺序
        /*
        if (nums.size() <= 1)
            return nums;
        int oddIndex = 1;
        int evenIndex = 0;
        
        while (oddIndex < nums.size() &&
              evenIndex < nums.size())
        {
            //如果遇上的是偶数的话，就一直走, 也可以使用nums[evenIndex] % 2 == 0, 来判断是否是偶数
            //这里 ()要多用，因为编译器可能会判断错
            while (evenIndex < nums.size() && ((nums[evenIndex] & 0x01) == 0))
            {
                evenIndex += 2;
            }
            
            //如果遇上的是奇数的话，就一直走, 也可以使用nums[evenIndex] % 2 != 0, 来判断是否是奇数
            //这里 ()要多用，因为编译器可能会判断错
            while (oddIndex < nums.size() && ((nums[oddIndex] & 0x01) != 0))
            {
                oddIndex += 2;
            }
            
            
            //如果两个index都没有走到尽头，那说明了，两个都指向了自己不应该指的数字
            //所以直接互换就可以了。
            if (oddIndex < nums.size() &&
              evenIndex < nums.size())
            {
                swap(nums[oddIndex], nums[evenIndex]);
            }
            else
            {
                break;
            }
        }
        
        return nums;
        */
    }
};