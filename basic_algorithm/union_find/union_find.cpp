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