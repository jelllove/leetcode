class Solution {
private:
    int maximum = 0;
    
    void partition (vector<int>& heights, int start, int end) {
        // stop if the partition start index >= end index
        if (start >= end)
            return;
        
        // partition height local minimum
        int minimum = heights[start];
        int min_index = start;
        
        // the flag is false if all elements of this array partition have the same value 
        int flag = false;
        for (int i = start + 1; i < end; i++) {
            // if there is a different value mark the flag as true
            if (heights[i] != minimum)
                flag = true;
            // get local minimum
            if (heights[i] < minimum) {
                minimum = heights[i];
                min_index = i;
            }
        }
        
        // the largest rectangle of this array partition is the minimum height * partition size
        // compare this local maximum with the global maximum
        maximum = max(minimum*(end - start), maximum);
        
        // if this flag is true it means that this partition of the array has all equal values
        if (!flag)
            return;
        
        // check the local maximum of the left array partition
        partition (heights, start, min_index);
        
        // check the local maximum of the right array partition
        partition (heights, min_index + 1, end);
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        partition(heights, 0, heights.size());
        return maximum;
    }
};