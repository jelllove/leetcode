class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 1)
            return true;
        //Method 1: BFS
        vector<int> table(numCourses + 1, -1); //index = 某一个课编号， value = {0, 有这个课，但它没有依赖，-1，代表没有这个课，其他的值代表这个课还有依赖}
        for (auto &p : prerequisites)
        {
            if (table[p[0]] == -1)
                table[p[0]] = 0;
            table[p[0]]++;
            
            if (table[p[1]] == -1)
                table[p[1]] = 0;
        }
        
        int total = 0;
        
        queue<int> q;
        
        for (int i = 0; i < table.size(); ++i)
        {
            if (table[i] == 0)
                q.push(i);
        }
        
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            table[val] = -1;
            
            
            for (auto &p : prerequisites)
            {
                if (p[1] == val)
                {
                    table[p[0]]--;
                    if (table[p[0]] == 0)
                    {
                        q.push(p[0]);
                    }
                }
            }
            
            ++total;
        }
        
        
        return (table == vector<int>(numCourses + 1, -1));
        
    }
};