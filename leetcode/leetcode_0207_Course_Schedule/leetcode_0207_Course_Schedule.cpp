class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 1)
            return true;
        //Method 1: BFS
        /*
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
        
        */
        
        //Method 2: BFS optimized
        //val + rely(vector)
        /*
        unordered_map<int, vector<int> > um;
        vector<int> table(numCourses, -1);
        
        for (auto &p : prerequisites)
        {
            if (um.count(p[1]) <= 0)
            {
                um[p[1]] = {p[0]};
            }
            else
            {
                um[p[1]].push_back(p[0]);
            }
            
            
            if (table[p[0]] == -1)
                table[p[0]] = 0;
            table[p[0]]++;
            
            if (table[p[1]] == -1)
                table[p[1]] = 0;
            
        }
        
        queue<int> q;
        
        int total = 0;
        for (int i = 0; i < table.size(); ++i)
        {
            if (table[i] == 0)
                q.push(i);
            
            if (table[i] != -1)
                ++total;
        }
        
        int done = 0;
        
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            
            table[val] = -1;
            for (auto &r : um[val])
            {
                table[r]--;
                if (table[r] == 0)
                    q.push(r);
            }
            
            ++done;
        }
        
        return done == total;
        */
        
        //Method 3: BFS + optimized 2
        /*
        vector<vector<int>> data(numCourses, vector<int>{});//代表了一个index是另外的index的输入
        vector<int> indegree(numCourses, 0);
        
        for (auto &p : prerequisites)
        {
            data[p[1]].push_back(p[0]);//建立p[0]和p[1]的主从关系
            indegree[p[0]]++;//入度加1
        }
        
        queue<int> que;
        
        
        
        for (int i = 0; i < indegree.size(); ++i)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }
        
        int finishCount = 0;
        
        while (!que.empty())
        {
            int course = que.front();
            que.pop();
            
            for (int k = 0; k < data[course].size(); ++k)
            {
                indegree[data[course][k]]--;
                if (indegree[data[course][k]] == 0)
                    que.push(data[course][k]);
            }
            ++finishCount;
        }
        
        
        return (finishCount == numCourses);
        */
        
        //Method 4: DFS, not good spped
        
        vector<int> footprint(numCourses, 0); //0 -- Not visited, 1 -- Visiting,  2 -- Finished
        
        vector<set<int>> adjOut(numCourses, set<int>{});
        vector<set<int>> adjIn(numCourses, set<int>{});
        for (auto &p : prerequisites)
        {
            adjOut[p[1]].insert(p[0]);//建立p[0]和p[1]的主从关系
            adjIn[p[0]].insert(p[1]);//建立p[0]和p[1]的主从关系
        }
        
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (footprint[i] == 0)
            {
                if (!helper(i, footprint, adjOut, adjIn))
                    return false;
            }
        }
        return true;
        
        
        
        
    }
    
    bool helper(int courseID, vector<int> footprint, vector<set<int>> &adjOut, vector<set<int>> &adjIn)
    {
        
        if (footprint[courseID] == 2)
            return true;
        else if (footprint[courseID] == 1)
            return false;
        
        
        footprint[courseID] = 1;
        
        
        for (auto &a : adjOut[courseID])
        {
            if (footprint[a] == 2)
                continue;
            else if (footprint[a] == 1)
                return false;
            else if (!helper(a, footprint, adjOut, adjIn))
                return false;
        }
        
        
        footprint[courseID] = 2;
        
        for (auto &a : adjIn[courseID])
        {
            adjOut[a].erase(courseID);
        }
        
        return true;
    }
};