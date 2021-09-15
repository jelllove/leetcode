class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        if (time <= 0 || clips.size() == 0)
            return -1;
        
        sort(clips.begin(), clips.end(), [](const vector<int> &a, const vector<int> &b){return a[0] <  b[0];});
        
        int clipTimes = 0;
        int curEnd = 0;
        int nextEnd = 0;
        int i = 0;
        int n = clips.size();
        while (i < n && clips[i][0] <= curEnd)
        {
            while (i < n && clips[i][0] <= curEnd)
            {
                nextEnd = max(nextEnd, clips[i][1]);
                ++i;
            }
                
            
            ++clipTimes;
            
            curEnd = nextEnd;
            if (curEnd >= time)
                return clipTimes;
            
        }
        
        return -1;
        
    }
};