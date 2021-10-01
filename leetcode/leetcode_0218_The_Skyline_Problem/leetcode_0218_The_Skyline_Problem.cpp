class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
     vector<pair<int,int>> heights;
        vector<vector<int>> res;
        for(auto x: buildings){
            heights.push_back(pair<int,int>(x[0],-x[2]));
            heights.push_back(pair<int,int>(x[1],x[2]));
        }
        sort(heights.begin(),heights.end());
        int prev=0,cur;
        multiset<int> st;
        st.insert(0);
        for(auto h: heights){
            if(h.second<0){st.insert(-h.second);}
            else{ st.erase(st.find(h.second));}
            cur= *st.rbegin();
            if(cur!=prev){
                vector<int> v{h.first,cur};
                res.push_back(v);
                prev=cur;
                
            }
            
        }
        
        return res;
    }
};