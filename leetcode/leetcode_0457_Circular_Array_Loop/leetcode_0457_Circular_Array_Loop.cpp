class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1)
            return false;
        
        
        
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
                continue;
            
            unordered_map<int, int> hash;
            int curPos = i;
            while (true)
            {
                int nextPos = (curPos + nums[curPos]) % n;
                if (nextPos < 0)
                    nextPos += n;
                
                if (curPos == nextPos || nums[curPos] * nums[nextPos] < 0)
                    break;
                
                if (hash.count(nextPos))
                    return true;
                visited[curPos] = true;
                hash[curPos] = nextPos;
                curPos = nextPos;
                
            }
        }
        
        return false;
        
    }
};