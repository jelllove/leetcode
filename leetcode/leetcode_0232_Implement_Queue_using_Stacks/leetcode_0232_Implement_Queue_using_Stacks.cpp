class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        
        //在真正插入之前，先把master中的元素都放到backup上
        while (!masterST.empty())
        {
            backupST.push(masterST.top());
            masterST.pop();
        }
        //然后在master上插入元素
        masterST.push(x);
        
        //再把刚才backup的元素都拿回来
        while (!backupST.empty())
        {
            masterST.push(backupST.top());
            backupST.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        if (masterST.empty())
            return 0;
        
        int ret = masterST.top();
        masterST.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (masterST.empty())
            return 0;
        
        return masterST.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return masterST.empty();
    }
    
private:
    stack<int> masterST;
    stack<int> backupST;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */