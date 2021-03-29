class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        //每次放一个新的元素时，就和最顶上的最小值比较一下，然后存下来最小的那个值
        //如果是空的话，那就让这个val和INT_MAX比较
        st.push(make_pair(val, min(val, st.empty() ? INT_MAX : st.top().second)));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
    
private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */