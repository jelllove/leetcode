class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Method 1, sort and using the sort and three ptr
        /*
        if (nums.size() < 3)
            return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        
        //Left, middle, right
        int l = 0, m = 1, r = nums.size() - 1;
        
        int tmp = 0;
        
        vector<vector<int>> ans;
        
        set<vector<int> > dup;
        
        while (l < (nums.size() - 2))
        {
            while (m < r)
            {
                tmp = nums[l] + nums[m] + nums[r];
                if (0 == tmp)
                {
                    vector<int> item = {nums[l], nums[m], nums[r]};
                    if (dup.count(item) == 0)
                    {
                        dup.insert(item);
                        ans.push_back(item);
                    }
                    
                    --r;
                    ++m;
                }
                else if (tmp > 0)
                {
                    --r;
                }
                else
                {
                    ++m;
                }
            }
            
            ++l;
            m = l + 1;
            r = nums.size() - 1;
        }
        
        
        return ans;
        */
        
        
        //Method 2, optimize the method 1, 
        /*
        if (nums.size() < 3)
            return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        
        set<int> sum;
        vector<vector<int>> ans;
        
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
                       
            sum.clear();
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (sum.find(-nums[i]-nums[j]) != sum.end())
                {
                    
                    ans.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                    
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                        ++j;
    
                }
                else
                {
                    sum.insert(nums[j]);
                }
            }
            
        }
        
        return ans;
        */
        
        
        //Method 3, the best
        if (nums.size() < 3)
            return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        
        //Left, middle, right
        int l = 0, m = 1, r = nums.size() - 1;
        
        int tmp = 0;
        
        vector<vector<int>> ans;
        
        for (l = 0; l < nums.size(); ++l)
        {
            m = l + 1;
            r = nums.size() - 1;
            
            if (l != 0 && nums[l] == nums[l - 1])
                continue;
        
            while (m < r)
            {
                tmp = nums[l] + nums[m] + nums[r];
                if (0 == tmp)
                {                    
                    ans.push_back({nums[l], nums[m], nums[r]});
                    
                    --r;
                    ++m;
                    
                    while (m < r && nums[m] == nums[m - 1])
                        ++m;
                    
                    while (m < r && nums[r] == nums[r + 1])
                        --r;
                    
                    
                }
                else if (tmp > 0)
                {
                    --r;
                }
                else
                {
                    ++m;
                }
            }
            
            
        }
        
        
        return ans;
    
    }
};