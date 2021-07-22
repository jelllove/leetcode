class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        if (nums.size() == 0)
            return {};
        
        sort(nums.begin(), nums.end());//一定要排序一下，要不然不可以
        
        vector<vector<int>> ret;
        ret.push_back({});
        int last = nums[0];
        int orgSize = 1;//这个代表了之前一次已经被处理过的数组的长度
        
        for (auto &n: nums)
        {
            if (last != n)
            {
                //如果这次新的数字和上一次不一样的，就说明前面的都要再COPY一次
                last = n;
                orgSize = ret.size();
            }
            //ELSE 否则的话，就原来的处理过的不要处理了，只要处理新的
            
            int curSize = ret.size();
            
            for (int i = curSize - orgSize; i < curSize; ++i)
            {
                ret.push_back(ret[i]);
                ret.back().push_back(n);
            }
        }
        
        return ret;
    }
};