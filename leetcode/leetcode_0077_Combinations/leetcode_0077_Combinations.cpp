class Solution {
public:
    
    void dfs(vector<vector<int>> &ans, vector<int> &subSet, int idx, int n, int k)
    {
        if (idx > n || subSet.size() >= k)
            return;
        
        for (int i = idx; i <= n; ++i)
        {
            subSet.push_back(i);
            if (subSet.size() == k)
                ans.push_back(subSet);
            dfs(ans, subSet, i + 1, n, k);
            subSet.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        if (n < 1 || k < 1)
            return {};
        
        
        
        //Method 1: using the dfs
        /*
        vector<vector<int>> ans;
        vector<int> subSet;
        dfs(ans, subSet, 1, n, k);
        */
        
        //Method 2: using the bit manipulation
        vector<vector<int>> ans;
        int amount = pow(2, n);
        vector<int> subSet(k, 0);
        for (int i = 1; i < amount; ++i)
        {
            bitset<20> bt(i);
            
            if (bt.count() == k)
            {
                int p = 0;
                for (int b = 0; b < 20; ++b)
                {
                    if (bt.test(b))
                    {
                        subSet[p++] = b + 1;
                    }
                }
                
                ans.push_back(subSet);
            }
        }
        
        return ans;
    }
};