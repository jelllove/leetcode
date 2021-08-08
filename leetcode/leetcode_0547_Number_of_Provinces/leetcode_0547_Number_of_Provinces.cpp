class CUnionFind
{
    
public:
    
    CUnionFind()
    {
        
    }
    
    CUnionFind(int num)
    {
        Resize(num);
    }
    
    void Union(int src, int dst)
    {
        if (src >= 0 && src < _union.size() &&
            dst >= 0 && dst < _union.size())
        {
            while (src != _union[src])
                src = _union[src];
            
            
            while (dst != _union[dst])
                dst = _union[dst];
            
            _union[src] = dst;
        }
            
    }
    
    int Find(int target)
    {
        if (target < 0 || target >= _union.size())
            return -1;
        
        
        while (target != _union[target])
            target = _union[target];
        
        return target;
    }
    
    void Clear()
    {
        _union.clear();
    }
    
    void Resize(int num)
    {
        if (num > 0)
            _union.resize(num);
        
        for (int i = 0; i < num; ++i)
            _union[i] = i;
    }
    
private:
    vector<int> _union;
};

class Solution {

private:
    CUnionFind _uf;

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        //Method 1: union find
        /*
        if (isConnected.size() == 0 || isConnected[0].size() == 0)
            return 0;
        
        int n = isConnected.size();
        
        _uf.Resize(n);
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (isConnected[i][j] == 1)
                    _uf.Union(i, j);
            }
        }
        
        int sum = 0;
        for (int k = 0; k < n; ++k)
        {
            if (_uf.Find(k) == k)
                ++sum;
        }
        
        return sum;
        */
        
        
        //Method 2: DFS
        int n = isConnected.size();
        if (n <= 1) return n;
        vector<bool> visited(n, false);
        
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ++sum;
                dfs(isConnected, i, visited);
            }
        }
        
        return sum;
    }
    
    void dfs(vector<vector<int>>& isConnected, int idx, vector<bool> &visited)
        {
            visited[idx] = true;
            for (int j = 0; j < isConnected.size(); ++j)
            {
                if (j != idx && isConnected[idx][j] && !visited[j])
                {
                    dfs(isConnected, j, visited);
                }
            }
        }
};