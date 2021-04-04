class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //Method 1: brute force,暴力破解法
        //方法是对的，但是数据大的时候，会超时
        /*
        if (T.size() == 0)
        {
            return vector<int>();
        }
        
        vector<int> ans(T.size(), 0);
        
        for (int i = 0; i < T.size() - 1; ++i)
        {
            for (int k = i + 1; k < T.size(); ++k)
            {
                if (T[i] < T[k])
                {
                    ans[i] = k - i;
                    break;
                }
            }
        }
        
        return ans;
        */
        
        //Method 2: Using the stack.
        if (T.size() == 0)
            return vector<int>();
        
        vector<int> ans(T.size(), 0);
        stack<int> stIndex;//Store the index
        
        for (int i = 0; i < T.size(); ++i)
        {
            while (!stIndex.empty())
            {
                if (T[i] > T[stIndex.top()])
                {
                    ans[stIndex.top()] = i - stIndex.top();
                    stIndex.pop();
                }
                else
                {
                    break;
                }
            }
            
            stIndex.push(i);
        }
        
        return ans;
        
    }
};