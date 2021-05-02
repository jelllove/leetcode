class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        //Method 1: using the sort
        //没想到这个是最快的
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
        
        
        //Method 2: using the set
        /*
        unordered_set<int> checkSet;
        
        for (auto &n : nums)
        {
            if (checkSet.count(n) >= 1)
                return true;
            else
                checkSet.insert(n);
        }
        return false;
        */
        
        //Method 3: using the map
        /*
        unordered_map<int, int> checkMap;
        
        for (auto &n : nums)
        {
            checkMap[n]++;
            if (checkMap[n] > 1)
                return true;
        }
        return false;
        */
        
        
        //Method 4: using the sort & unique
        /*
        std::sort(nums.begin(), nums.end());
        
        //unique这个函数是对一个数组中，两两相近的元素进行去重，但是它不是删除操作，它只是利用现在的空间，把重复的元素放到了最后
        //比如： 1,2,2,3,3,4   使用了unique(nums.begin(), nums.end())之后，会变成：
        //       1,2,3,4,2,3,  最后返回的值是指向第二个2的一个指针
        //   所有一般要把一个数组的元素删除掉，会这样做：
        //   std::sort(nums.begin(), nums.end());
        //   auto iter = unique(nums.begin(), nums.end());
        //   nums.erase(iter, nums.end());
        //---------------------------------------------
        auto iter = unique(nums.begin(), nums.end());
        
        return iter != nums.end();
        */
        
    }
};