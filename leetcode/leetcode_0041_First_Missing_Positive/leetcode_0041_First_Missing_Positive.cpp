class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Method 1: sort and find, but low efficiency.
        /*
        sort(nums.begin(), nums.end());
        
        int minValue = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0 && minValue != nums[i])
            {
                if ((nums[i] - minValue) == 1)
                {
                    minValue = nums[i];
                }
                else
                {
                    return minValue + 1;
                }
            }
        }
        
        return minValue == 0 ? 1 : minValue + 1;
        */
        
        //Method 2:  using the min heap
        /*
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &n : nums)
        {
            if ((pq.empty() || pq.top() != n) && n > 0)
            {
                pq.push(n);
            }
        }
        
        int m = 0;
        int t = 0;
        while (!pq.empty())
        {
            t = pq.top();
                        
            if (t - m > 1)
            {
                return m + 1;
            }
            else if (t - m == 1)
            {
                m = t;
            }
            
            pq.pop();
        }
        
        return m + 1;
        */
        
        //Method 3: using the histogram filling
        /*
        int n = nums.size();
        vector<bool> histogram(n, false);
        
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0 && nums[i] <= n)
            {
                histogram[nums[i] - 1] = true;
            }
        }
        
        for (int j = 0; j < n; ++j)
        {
            if (!histogram[j])
                return j + 1;
        }
        
        return n + 1;
        */
        
        //Method 4: using the swap method, but it looks, it is not so quickly
        /*
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                ++i;
        }
        
        i = 0;
        while (i < n)
        {
            if (nums[i] != i + 1)
                return i + 1;
            else
                ++i;
        }
        
        return n + 1;
        */
        /*
        sort(nums.begin(), nums.end());
        int f = 1;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= 0)
                continue;
            else if (i > 0 && nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == f)
                ++f;
            else
                return f;
        }
        
        return f;
        */
        
        unordered_set<int> set(nums.begin(), nums.end());
        int i;
        for (i = 1; i <= nums.size(); ++i)
        {
            if (set.count(i) == 0)
                return i;
        }
        
        return i;
    }
};