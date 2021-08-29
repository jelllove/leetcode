class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        unordered_map<int, int> hash;
        
        priority_queue<int> pq;
        
        for (int i = 0; i < k; ++i)
        {
            hash[nums[i]]++;
            pq.push(nums[i]);
        }
        
        ans.push_back(pq.top());
        
        for (int i = k; i < nums.size(); ++i)
        {
            hash[nums[i - k]]--;
            
            pq.push(nums[i]);
            hash[nums[i]]++;
            
            while (hash[pq.top()] == 0)
                pq.pop();
            
            ans.push_back(pq.top());
        }
        
        return ans;
        
        
    }
};



//Solution 2
template<class T>
class MyDeque
{
public:
    void push(T n)
    {
        while (!m_deque.empty() && m_deque.back() < n)
            m_deque.pop_back();
        m_deque.push_back(n);
    }
    
    void pop(T n)
    {
        if (!m_deque.empty() && m_deque.front() == n)
            m_deque.pop_front();
    }
    
    T getMax()
    {
        if (!m_deque.empty())
            return m_deque.front();
        else
            return T();
    }
    
private:
    deque<T> m_deque;
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        MyDeque<int> myDeque;
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            myDeque.push(nums[i]);
            
            if (i < k - 1)
            {
                continue;
            }
            else if (i == k - 1)
            {
                ans.push_back(myDeque.getMax());
            }
            else
            {
                myDeque.pop(nums[i - k]);
                ans.push_back(myDeque.getMax());
            }
        }
        
        return ans;
    }
};
