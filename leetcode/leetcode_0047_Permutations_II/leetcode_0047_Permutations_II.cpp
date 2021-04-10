class Solution {
public:
    
    
    
    vector<int> path;
    vector<bool> visited;
    vector<vector<int>> ans;
    
    
    //Method 4:dfs + 交替法
    //只改变原来数组的位置，不是很好理解，但是对于没有重复的数组来说可能好理解一点
    //特别是对于类似于
    /*void dfs(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            if (find(ans.begin(), ans.end(), nums) == ans.end())
                ans.push_back(nums);
            return;
        }
        
        for (int i = index; i <= nums.size() - 1; ++i)
        {
            swap(nums[i], nums[index]);
            dfs(nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }*/
    
    
    
    //Method 3:使用dfs+回溯，然后没有使用剪枝法
    //速度慢，好理解
    /*
    void dfs(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            if (find(ans.begin(), ans.end(), path) == ans.end())
                ans.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            
            if (!visited[i])
            {
                
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, index + 1);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
    */
    
    
    //Method 3:使用dfs+回溯，然后使用剪枝法
    //如果输入是无重复的，可以不使用剪枝法
    //但是对于有重复的，一定要使用剪枝法去掉重复的，比如1, 1, 2
    /*void dfs(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            
            if (!visited[i])
            {
                //如果是有重复的元素的，一定要用这个剪枝法，要不然，就会出现一样的排列
                if(i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == false) 
                   continue;
                
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, index + 1);
                visited[i] = false;
                path.pop_back();
            }
        }
    }*/
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        //Method 1: 
        /*sort(nums.begin(), nums.end());
        visited = vector<bool>(nums.size(), false);
        dfs(nums, 0);
        
        
        return ans;
        */
        //Method 2: 使用next_permutation
        //方便，好用
        
        vector<vector<int>> ans;
        //使用next_permutation时，要进行一个排序
        sort(nums.begin(), nums.end());
        do
        {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};