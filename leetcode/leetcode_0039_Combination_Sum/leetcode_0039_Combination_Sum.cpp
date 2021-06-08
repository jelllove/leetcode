class Solution {

private:
    vector<vector<int>> ans;
    
public:
    
    void dfs(vector<int>& candidates, int i, vector<int> tmp, int sum, int target)
    {
        if (i >= candidates.size())
            return;
        
        if (sum + candidates[i] > target)
            return;
        else if (sum + candidates[i] == target)
        {
            tmp.push_back(candidates[i]);
            ans.push_back(tmp);
            return;
        }
        else
        {
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            for (int k = i; k < candidates.size(); k++)
            {
                dfs(candidates, k, tmp, sum, target);
            }
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        
        if (candidates.size() == 0 || (candidates.size() == 1 && candidates[0] < target))
        {
            return ans;
        }
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> tmp;
        for (int i = 0; i < candidates.size(); ++i)
            dfs(candidates, i, tmp, 0, target);
        
        return ans;
        
    }
};