class Solution {

public:
    
    bool helper(int courseID, vector<vector<int>> &adj, vector<bool> &noVisited, vector<bool> &isVisiting, vector<bool> &hasDone, vector<int> &finishOrder)
    {
        noVisited[courseID] = false;
        isVisiting[courseID] = true;
        
        for (auto &a : adj[courseID])
        {
            if (hasDone[a])
                continue;
            if (isVisiting[a])
                return false;
            
            if (!helper(a, adj, noVisited, isVisiting, hasDone, finishOrder))
                return false;
        }
    
        isVisiting[courseID] = false;
        hasDone[courseID] = true;
        finishOrder.push_back(courseID);
        
        return true;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        vector<int> finishOrder;//使用一个stack来存放一个个课程完成的顺序
        vector<vector<int>> adj(n, vector<int>{});
        
        vector<bool> noVisited(n, true);
        vector<bool> isVisiting(n, false);
        vector<bool> hasDone(n, false);
            
        
        //生成邻居关系
        for (auto &i : p)
        {
            adj[i[1]].push_back(i[0]);
        }
        
        //一个个访问
        for (int k = 0; k < n; k++)
        {
            //如果已经被访问过了，就不用了，肯定它肯定已经入栈了
            if (noVisited[k])
            {
                //如果访问时出现了回环之类的，就直接失败
                if (!helper(k, adj, noVisited, isVisiting, hasDone, finishOrder))
                    return vector<int>{};
            }
            
        }
        
        reverse(finishOrder.begin(), finishOrder.end());
        //最后把stack中的信息反转一下，当然也可以使用vector
        return finishOrder;
        
    }
};