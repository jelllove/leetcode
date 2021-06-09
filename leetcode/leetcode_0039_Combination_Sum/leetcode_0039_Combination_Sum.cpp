class Solution {

private:
    vector<vector<int>> ans;
    
public:
    
    void dfs(vector<int>& candidates, int i, vector<int> &tmp, int target, int n)
    {
        if (i >= n || target < 0)
            return;
        
        if (0 == target)
        {
            ans.push_back(tmp);
            return;
        }
        else
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, i, tmp, target - candidates[i], n);
            tmp.pop_back();
            dfs(candidates, i + 1, tmp, target, n);
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        
        if (candidates.size() == 0 || (candidates.size() == 1 && candidates[0] > target))
        {
            return ans;
        }
        
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> tmp;
        dfs(candidates, 0, tmp, target, candidates.size());
        
        return ans;
        
    }
};