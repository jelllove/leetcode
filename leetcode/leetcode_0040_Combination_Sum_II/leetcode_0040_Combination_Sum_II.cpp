/* Method 1: using the recursion
class Solution {

private:
    map<vector<int>, bool> ans;
    
public:
    
    void dfs(vector<int>& candidates, int i, vector<int> &tmp, int target, int n)
    {
        if (i >= n && target != 0)
            return;
        
        if (target < 0)
        {
            return;
        }
        else if (0 == target)
        {
            ans[tmp] = true;
            return;
        }
        else
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, i + 1, tmp, target - candidates[i], n);
            tmp.pop_back();
            dfs(candidates, i + 1, tmp, target, n);
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        
        if (candidates.size() == 0 || (candidates.size() == 1 && candidates[0] > target))
        {
            return vector<vector<int>>{};
        }
        
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> tmp;
        dfs(candidates, 0, tmp, target, candidates.size());
        
        vector<vector<int>> ret;
        for (auto &a : ans)
            ret.push_back(a.first);
        
        return ret;
        
    }
};
*/


class Solution {

    
public:
    
    void helper(vector<int>& candidates, vector<vector<int>> &ans, int index, vector<int> &tmp, int target)
    {
        if (index >= candidates.size() && target != 0)
            return;
        
        if (target < 0)
        {
            return;
        }
        else if (0 == target)
        {
            ans.push_back(tmp);
            return;
        }
        else
        {
            for (int i = index; i < candidates.size(); ++i)
            {
                //因为前面已经排序过了，所以这里只要比较一下，是不是前一个和当前的是相同的话，那就已经过滤类似{1, 1, 1, 2,5}这种
                if (i == index || (candidates[i] != candidates[i - 1]))
                {
                    tmp.push_back(candidates[i]);
                    helper(candidates, ans, i + 1, tmp, target - candidates[i]);
                    tmp.pop_back();
                }
            }
            
            
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        if (candidates.size() == 0 || (candidates.size() == 1 && candidates[0] > target))
        {
            return vector<vector<int>>{};
        }
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> tmp;
        
        helper(candidates, ans, 0, tmp, target);
        
        
        return ans;
        
    }
};