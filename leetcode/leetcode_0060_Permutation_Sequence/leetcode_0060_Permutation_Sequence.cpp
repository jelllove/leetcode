class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {

        if (nums.size() <= 1)
            return;
        

        int n = nums.size();
        int i = n - 2;
        
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        
        if (i >= 0)
        {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i])
                --j;
            
            swap(nums[i], nums[j]);
        }
        
        reverse(nums.begin() + i + 1, nums.end());
        
        
    }
    
    string getPermutation(int n, int k) {
        
        if (n == 1)
            return "1"s;
        
        int amount = 1;
        for (int i = 2; i <= n; ++i)
        {
            amount *= i;
        }
        
        int reset = k;
        
        //if ((amount - 1) != 1 && (k != (amount - 1)))
        //    reset = k % (amount - 1);
            
        
        vector<int> data(n, 0);
        for (int i = 1; i <= n; ++i)
        {
            data[i - 1] = i;
        }
        
        for (int i = 0; i < reset - 1; ++i)
        {
            nextPermutation(data);
        }
        
        string ans = "";
        
        for (auto &s : data)
        {
            ans += to_string(s);
        }
        
        return ans;
        
    }
};