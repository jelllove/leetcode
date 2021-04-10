class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Method 1: using sort
        /*
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
                
        }
        */
        
        //Method 2: using the hash table
        /*
        //pair = value + count
        unordered_map<int, int> um;
        
        for (auto &n : nums)
        {
            um[n]++;
            if (um[n] >= 2)
                return n;
        }
        
        return 0;
        */
        
        //Method 3: 因为题目限制了这个数组的值只能是从1到N之间
        //那么可以利用i 从1到n之间进行遍历，然后对相当的index进行一个取负值的操作
        //如果发现这个值已经被取过一次负值了，那就是重复的
        /*
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            int value = abs(nums[i]);
            int index = value - 1;
            
            if (nums[index] > 0)
            {
                nums[index] *= -1;
            }
            else
            {
                return value;
            }
        }
        
        return 0;
        */
        
        //Method 4: 
        int slow = nums[0];
        int fast = nums[0];
        
        //相当于利用两个快慢指针先找到那个相遇的点，然后，再让另一个回到起点
        //然后再一起走，这样就可以找到那个相同的点了
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        
        fast = nums[0];
        
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
    }
};