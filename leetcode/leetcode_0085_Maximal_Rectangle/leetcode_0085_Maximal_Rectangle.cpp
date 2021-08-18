class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        stack<int> st; h.push_back(-1); int res = 0;
        
        for(int i = 0 ; i < h.size() ; i++) {
            
            while(!st.empty() && h[st.top()] > h[i]) {
                
                int r = i;
                int n = h[st.top()]; st.pop();
                int l = st.empty() ? -1 : st.top();
                int w = r - l - 1;
                res = max(res, w * n);
            }
            st.push(i);
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& g) {
        
        if(g.size() == 0) return 0;
        vector<int> col(g[0].size(), 0); int res = 0;
        
        for(int i = 0 ; i < g.size() ; i++) {
            
            for(int j = 0 ; j < g[0].size(); j++)
                col[j] = g[i][j] == '0' ? 0 : col[j] + 1;

            vector<int> temp; for(auto c : col) temp.push_back(c);
            res = max(res, largestRectangleArea(temp));
        }
        
        return res;
    }
};