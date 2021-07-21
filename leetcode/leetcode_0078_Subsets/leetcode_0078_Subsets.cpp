class Solution {
public:
    //Method 1, using the additional insert
    /*
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ret;
        ret.push_back({});
        
        for (auto &nu : nums)
        {
            int size = ret.size();
            for (int i = 0; i < size; ++i)
            {
                ret.insert(ret.end(), ret[i]);    
            }

            while (size < ret.size())
            {
                ret[size].push_back(nu);
                ++size;
            }
        }
        
        return ret;
    }
    */
    
    //Method 2, using the bitset
    /*
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ret;
        ret.push_back({});
        unsigned long amount = pow(2, nums.size());
        
        for (unsigned long i = 1; i < amount; ++i)
        {
            bitset<32> bt(i);
            vector<int> vec;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (bt[j])
                {
                    vec.push_back(nums[j]);
                }
            }
            
            ret.push_back(vec);
        }
        
        
        return ret;
    }
    */
    
    //Method 3: using the dfs
    
    void helper(int idx, vector<int>& nums, vector<int>& sub_set, vector<vector<int>> &ans)
    {
        
        ans.push_back(sub_set);
        
        for (int i = idx; i < nums.size(); ++i)
        {
            sub_set.push_back(nums[i]);
            helper(i + 1, nums, sub_set, ans);
            sub_set.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        
        vector<vector<int>> ans;
        vector<int> sub_set;
        
        helper(0, nums, sub_set, ans);
        
        return ans;
    }
};