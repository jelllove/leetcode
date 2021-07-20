class Solution {
    
private:
    vector<vector<int>> ans;
public:
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2)
            return {};
        
        //Method 1: using the bit for traverse all possible combination.
        vector<int> tmp;
        set< vector<int> > dup;
        
        int possible = pow(2, nums.size()) - 1;
        
        for (int i = 3; i <= possible; ++i)
        {
            bitset<15> bt(i);
            
            vector<int> tmp;
            int n = nums.size();
            
            for (int k = 0; k < nums.size(); ++k)
            {
                if (bt.test(k))
                {
                    if (tmp.size() == 0 || nums[k] >= tmp.back())
                        tmp.push_back(nums[k]);
                    
                    if (tmp.size() >= 2 && dup.count(tmp) == 0)
                    {
                        dup.insert(tmp);
                        ans.push_back(tmp);
                    }
                }
            }
        }
        
        return ans;
    }
};