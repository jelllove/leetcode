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
        
        //Method 1: using the buste force
        /*
        if (n == 1)
            return "1"s;
        
        int amount = 1;
        for (int i = 2; i <= n; ++i)
        {
            amount *= i;
        }
        
        int reset = 0;
        
        if (k <= amount)
            reset = k - 1;
        else
            reset = (k - 1) % amount;
            
        
        
        
        //if ((amount - 1) != 1 && (k != (amount - 1)))
        //    reset = k % (amount - 1);
            
        
        vector<int> data(n, 0);
        for (int i = 1; i <= n; ++i)
        {
            data[i - 1] = i;
        }
        
        for (int i = 0; i < reset; ++i)
        {
            nextPermutation(data);
        }
        
        string ans = "";
        
        for (auto &s : data)
        {
            ans += to_string(s);
        }
        
        return ans;
        */
        
        //Method 2: using the math algorithm
        string nums = "123456789";
        vector<int> f(n, 1);
        
        //把每一个n对应的阶乘都先算出来
        for (int i = 1; i < n; ++i)
            f[i] = f[i - 1] * i;
        
        string res = "";
        --k;
        while (n >= 1)
        {
            //先算取要从nums中取第几个值
            int a = k / f[n - 1];
            //把k改成下一次的，因为取了一次之后，下次就要从小的里去取了
            //比如n = 7, k = 17，那取了第一个数之后，因为要从剩下的N=3中去取了，所以要取模
            k %= f[n - 1];
            //把对应的nums的值放到数组中
            res.push_back(nums[a]);
            //同时从nums中删除它
            nums.erase(a, 1);
            --n;
        }
        
        return res;
        
    }
};