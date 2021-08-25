class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int>v(n,1);
        for(int i = 1 ; i < n ; i++)
        {
            if(r[i]>r[i-1])
            {
                v[i] = v[i-1]+1;
            }
        }
        for(int i = n-2 ; i >= 0 ; i--)
        {
            if(r[i]>r[i+1] && v[i]<=v[i+1])
            {
                v[i] = v[i+1]+1;
            }
        }
        int s = 0;
        for(int i = 0 ; i < n ; i++)
        {
            s = s + v[i];
        }
        return s;
    }
};