class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if (gas.size() != cost.size() || gas.size() == 0)
            return -1;
        
        int n = gas.size();
        
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i)
        {
            if (gas[i] < cost[i] || visited[i])
                continue;
            
            
            int tank = gas[i];
            int curPos = i;
            
            while (true)
            {
                int nextPos = (curPos + 1) % n;
                
                if (tank < cost[curPos])
                    break;
                
                tank = tank - cost[curPos] + gas[nextPos];
                visited[curPos] = true;
                curPos = nextPos;
                if (curPos == i)
                    return i;
            }
        }
        
        return -1;
    }
};