class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int sum = 0;
        //如果当前只有三个数，那只能返回的总和
        if (nums.size() <= 3)
        {
            for (auto &item : nums)
                sum += item;
            return sum;
        }
        
        //一定要排序，如果不排的话，那就没办法使用三个指针了
        sort(nums.begin(), nums.end());
        
        
        int l, m, r;
        int minDis = INT_MAX; //记录所有最小的距离
        
        //因为还有一个m和r的指针，所以遍历l的时候，不能遍历全部
        for (l = 0; l < nums.size() - 2; ++l)
        {
            m = l + 1;
            r = nums.size() - 1;//每次r都要指向尾部
            
            while (m < r)
            {
                //算出和
                sum = (nums[l] + nums[r] + nums[m]);
                
                //如果发现这次的和，与目标的差距，跟上一次比较起来更近了，就保存起来
                //所以要用abs取绝对值
                if (minDis > abs(sum - target))
                {
                    minDis = abs(sum - target);
                    res = sum;
                }
                
                //如果相等直接返回
                if (sum == target)
                    return sum;
                else if (sum < target)
                    ++m; //说明可以让和再增加一点。
                else
                    --r;
            }
        }
        
        return res;
            
    }
};