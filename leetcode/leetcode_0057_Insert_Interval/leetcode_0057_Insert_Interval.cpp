class Solution {

    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        //Method 1: traverse, this method is work, but low efficiency
        if (newInterval.size() == 0)
            return intervals;
        if (intervals.size() == 0)
            return vector<vector<int>>{{newInterval[0],newInterval[1]}};
        
        
        vector<vector<int>> ans;
        bool inserted = false;
        
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (inserted)
            {
                ans.push_back(intervals[i]);
                continue;
            }
            
            
            if (intervals[i][0] > newInterval[1])
            {
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                inserted = true;
            }
            else if (intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else 
            {
                if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1])
                {
                    newInterval[0] = intervals[i][0];
                }
                
                
                if (intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1])
                {
                    newInterval[1] = intervals[i][1];
                }
            }
        }
        
        if (!inserted)
            ans.push_back(newInterval);
        
        
        sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        return ans;
        
        /*
        
        INDEX_STATUS s_status = IS_AFTER;
        int s = -8;
        
        INDEX_STATUS e_status = IS_AFTER;
        int e = -8;
        
        for (int i = 0; i < intervals.size() && (s == -8 || e == -8); ++i)
        {
            if (s == -8)
            {
                if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1])
                {
                    s = i;
                    s_status = IS_IN;
                }
                else if (newInterval[0] < intervals[i][0])
                {
                    s = i ;
                    s_status = IS_BEFORE;
                }
            }
            
            if (e == -8)
            {
                if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1])
                {
                    e = i;
                    e_status = IS_IN;
                }
                else if (newInterval[1] < intervals[i][0])
                {
                    e = i;
                    e_status = IS_BEFORE;
                }
            }
            
        }
        
        
        if (e == s)
            intervals.push_back(newInterval);
        else
        {
            if (s_status == IS_IN)
            newInterval[0] = min(newInterval[0], intervals[s][0]);
        else if (s_status == IS_AFTER)
            s = intervals.size() + 1;
        
        if (e_status == IS_IN)
            newInterval[1] = max(newInterval[1], intervals[e][1]);
        else if (e_status == IS_AFTER)
            e = intervals.size() + 1;
        
        for (int k = e; k >= s; --k)
        {
            if (k >= 0 && k < intervals.size())
                intervals.erase(intervals.begin() + k);
        }
        
        intervals.push_back(newInterval);
        }
        
        
        
        
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        
        
        return intervals;
        */
        
        /*
        int maxVal = INT_MIN;
        
        for (auto &i : intervals)
        {
            maxVal = max(maxVal, i[i.size() - 1]);
        }
        
        
        for (auto &i : newInterval)
        {
            maxVal = max(maxVal, i);
        }
        
        if (maxVal == INT_MIN)
        {
            vector<vector<int>> ans;
            ans.push_back(newInterval);
            return ans;
        }
        
        
        vector<bool> data(maxVal + 1, false);
        
        for (auto &i : intervals)
        {
            for (int k = i.front(); k < i.back(); ++k)
            {
                data[k] = true;
            }
        }
        
        if ()
        for (int k = newInterval.front(); k < newInterval.back(); ++k)
        {
            data[k] = true;
        }
        
        bool start = false;
        int num = -1;
        
        
        
        vector<vector<int>> ans;
        
        for (int m = 0; m < data.size(); ++m)
        {
            if (data[m])
            {
                if (!start)
                {
                    num = m;
                    start = true;
                }
            }
            else
            {
                if (start)
                {
                    start = false;
                    ans.push_back(vector<int>{num, m});
                    num = -1;
                }
            }
        }
        
        return ans;
        
        */
    }
};