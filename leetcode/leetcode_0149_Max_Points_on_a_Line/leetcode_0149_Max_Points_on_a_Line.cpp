class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;        
        for(int i=0; i<points.size()-1; i++){
            unordered_map<double,int> mem; // slope->count
            for(int j=i+1; j<points.size(); j++){
                int deltaX = points[i][0] - points[j][0];
                int deltaY = points[i][1] - points[j][1];
                double slope = deltaX==0? INT_MAX : deltaY*1.0/deltaX;
                mem[slope]++;           
				res = max(res, mem[slope]+1);
            }
        }
        return res;
    }
};