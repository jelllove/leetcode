class Solution {
public:
    string reorganizeString(string S) {
        
        
        //如果只有一个或没有字符的话，那就直接返回
        if (S.size() < 2)
            return S;
        
        
        //生成一个HASH表，用来表示S字符串中，每一个字母出现了多少次
        unordered_map<char, int> um;
        
        for (auto c : S)
        {
            um[c]++;
        }
        
        
        //生成一个pair的优先堆，存放以次数优先的一对对数据
        priority_queue<pair<int, char>> pq;
        for (auto &u : um)
        {
            pq.push(make_pair(u.second, u.first));
        }
        
        
        //从堆的顶开始，两个两个的进行取值
        
        //如果计数没有减成0的话，就放回去
        string ans;
        while (pq.size() > 1) //至少要有两个元素以上才可以
        {
            
            //拿了两个数据出来，
            auto p = pq.top();
            pq.pop();
            auto q = pq.top();
            pq.pop();
            
            //就排列到ans中
            ans += p.second;
            ans += q.second;
            
            //并将它们的计数减速1
            p.first--;
            q.first--;
            
            //如果计数还大于等于1,那就放回去
            //因为是优先堆，所以其实没有先后关系
            if (q.first >= 1)
                pq.push(q);
            if (p.first >= 1)
                pq.push(p);
        }
        
        if (!pq.empty())
        {
            //最后有可能这个堆里已经没有元素了，也可能还有一个元素
            //只要这个元素的计数等于1，那就没事，要不然，那就是不成立的
            if (pq.top().first == 1)
                return ans + pq.top().second;
            else
                return "";
        }
        
        return ans;
    }
};