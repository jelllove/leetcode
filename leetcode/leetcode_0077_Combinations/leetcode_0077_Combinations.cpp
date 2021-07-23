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
        vector<vector<int>> ans;
        vector<int> subSet;
        
        dfs(ans, subSet, 1, n, k);
        
        return ans;
    }
};