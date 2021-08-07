class Solution {

struct wordCMP
{
    bool operator () (const pair<string, int> &a, const pair<string, int> &b)
    {
        if (a.second > b.second)
            return true;
        else if (a.second == b.second)
            return a.first < b.first;
        else
            return false;
    }
};

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> hash;
        
        for (auto &str : words)
        {
            hash[str]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, wordCMP> pq;
        
        for (auto &h : hash)
        {
            if (pq.size() < k)
                pq.push(h);
            else
            {
                if (pq.top().second < h.second)
                {
                    pq.pop();
                    pq.push(h);
                }
                else if (pq.top().second == h.second)
                {
                    pq.push(h);
                    pq.pop();
                }
                    
            }
        }
        
        vector<string> ans(k, "");
        int idx = k - 1;
        while (!pq.empty())
        {
            ans[idx--] = pq.top().first;
            pq.pop();
        }
        
        return ans;
    }
};