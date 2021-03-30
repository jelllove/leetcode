struct compare {
        bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        }
    };

class Solution {
public:
    //Method 1: using the full elements insert into the heap
    // and also using the lambda as the compare functionality
    /*
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //hash<int, int> = hash<value, frequence>
        unordered_map<int, int> hash;
        
        for (auto &item : nums)
        {
            hash[item]++;
        }
        
        
        //pair<int, int> = pair<value, frequence>
        //priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b){return a.second < b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        for (auto &h : hash)
        {
            pq.push(h);
        }
        
        vector<int> ans;
        for (int i = 0; i < k && !pq.empty(); ++i)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
    */
    
    //Method 2: using the K elements insert into the heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //hash<int, int> = hash<value, frequence>
        unordered_map<int, int> hash;
        
        for (auto &item : nums)
        {
            hash[item]++;
        }
        
        
        //pair<int, int> = pair<value, frequence>
        //priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        //因为这次只使用了K个元素，所以要弄一个最小堆
        //不过，结果好像还没有上一个方法来得快
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b){return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        int maxFreq = INT_MIN;
        for (auto &h : hash)
        {
            if (pq.size() < k)
                pq.push(h);
            else
            {
                if (h.second > pq.top().second)
                {
                    pq.pop();
                    pq.push(h);
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < k && !pq.empty(); ++i)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};