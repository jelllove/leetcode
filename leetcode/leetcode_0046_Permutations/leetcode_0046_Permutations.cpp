class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int>& nums, int idx)
    {
        
        if (idx == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        
        for (int i = idx; i <= (nums.size() - 1); ++i)
        {
            swap(nums[i], nums[idx]);
            helper(ans, nums, idx + 1);
            swap(nums[i], nums[idx]); 
        }
    }
    
    void my_next_permutation(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return;
        
        int i = nums.size() - 2;
        int j =  nums.size() - 1;
        
        //先找到那个尾部第一个是降序的元素
        while (i >= 0)
        {
            if (nums[i + 1] > nums[i])
                break;
            else
                --i;
        }
        
        //如果一直都没有找到的话，那就是整个数组是降序的，
        
        if (i >= 0)
        {
            //如果有找到降序的话，再从尾部开始找，找到第一个比较它大的值
            while (j > i && nums[j] < nums[i])
            {
                --j;
            }
            //交换它们
            swap(nums[i], nums[j]);
        }
        
        reverse(nums.begin() + i + 1, nums.end());
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        //Method 1: using the backtrack method
        /*
        vector<vector<int>> ans;
        helper(ans, nums, 0);
        
        return ans;
        */
        
        //Method 2: using the alogrithm of next_permutation.
        //first to sort
        sort(nums.begin(), nums.end());
        
        vector<int> org = nums;
        vector<vector<int>> ans;
        do
        {
            ans.push_back(nums);
            my_next_permutation(nums);
        } while (nums != org);
        
        return ans;
    }
};