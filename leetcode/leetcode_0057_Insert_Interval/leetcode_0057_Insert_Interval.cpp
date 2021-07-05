class Solution {
private:
    vector<int> merge(vector<int> &a, vector<int> &b)
    {
        if ((a[0] >= b[0] && a[0] <= b[1]) ||
            (a[1] >= b[0] && a[1] <= b[1]) ||
            (b[0] >= a[0] && b[0] <= a[1]) ||
            (b[0] >= a[0] && b[1] <= a[1]))
        {
            return {min(a[0], b[0]), max(a[1], b[1])};
        }
        else
            return {};
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        //Method 1: traverse, this method is work, but low efficiency
        /*
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
        
        */
        
        //Method 2: using the merge method
        if (newInterval.size() == 0)
            return intervals;
        if (intervals.size() == 0)
            return vector<vector<int>>{{newInterval[0],newInterval[1]}};
        
        //Add the new into the set
        intervals.push_back(newInterval);
        
        //sort
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        
        vector<int> current = intervals[0];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> tmp = merge(current, intervals[i]);
            if (tmp.size() == 0)
            {
                ans.push_back(current);
                current = intervals[i];
            }
            else
            {
                current = tmp;
            }
        }
        
        ans.push_back(current);
        
        return ans;
       
    }
};