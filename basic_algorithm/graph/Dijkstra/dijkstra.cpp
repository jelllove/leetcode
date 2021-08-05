class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        //Method 1: Dijkstra method
        //Store the adjacent info
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &t : times)
        {
            if (adj.count(t[0]) >= 1)
                adj[t[0]].push_back({t[1], t[2]});
            else
                adj[t[0]] = {{t[1], t[2]}};
        }
        
        //store the visited situation
        vector<bool> visited(n + 1, false);
        
        //Store the distance info from the node K
        vector<int> dist(n + 1, INT_MAX);
        
        //store the previous node which reach the 
        vector<int> prev(n + 1, -1);
        
        //set the start node's info
        dist[k] = 0;
        prev[k] = k;
        
        //using the count to statistic all the 
        int count = 0;
        while (count < n)
        {
            
            int target = -1;
            int minDist = INT_MAX;
            int idx = -1;
            
            //get the target which has the mini distance, and not visited yet.
            for (int i = 1; i <= n; ++i)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    idx = i;
                    minDist = dist[i];
                }
            }
            
            //if there is none target, that mean some node is unreachable.
            if (idx == -1)
                return -1;
            else
            {
                //Adjust the distance of the target's adjacent's distance
                for (auto &e : adj[idx])
                {
                    if (visited[e.first])
                        continue;
                    
                    if (dist[e.first] > (dist[idx] + e.second))
                    {
                        dist[e.first] = (dist[idx] + e.second);
                        prev[e.first] = idx;
                    }
                }
            }
            visited[idx] = true;
            ++count;
        }
        
        //Find out the max distance from the node K to all the nodes.
        int len = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            len = max(len, dist[i]);
        }
        
        return len;
        
        
        //Method 2: using the BFS
        //Store the adjacent info
        /*
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &t : times)
        {
            if (adj.count(t[0]) >= 1)
                adj[t[0]].push_back({t[1], t[2]});
            else
                adj[t[0]] = {{t[1], t[2]}};
        }
        
        //store the visited situation
        vector<bool> visited(n + 1, false);
        
        //Store the distance info from the node K
        vector<int> dist(n + 1, INT_MAX);
        queue<int> q;
        
        int count = 1;
        dist[k] = 0;
        q.push(k);
        int len = 0;
        
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                int idx = q.front();
                q.pop();
                visited[idx] = true;
                for (auto &e : adj[idx])
                {
                    dist[e.first] = min(dist[e.first], dist[idx] + e.second);
                    
                    if (visited[e.first])
                        continue;
                    q.push(e.first);
                    ++count;
                }
            }
        }
        
        if (count < n)
            return -1;
        
        int ret = *max_element(dist.begin() + 1, dist.end());
        
        return ret == INT_MAX ? -1 : ret;
        
        */
            
        
    }
};