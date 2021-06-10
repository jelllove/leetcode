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
    }
};