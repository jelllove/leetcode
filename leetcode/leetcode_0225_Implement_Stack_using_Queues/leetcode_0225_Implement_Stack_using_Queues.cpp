class MyStack {
public:
    
    
    /** Initialize your data structure here. */
    MyStack() {
        //先让master指针和backup指针都指向一个queue
        ptrMasterQ = &queA;
        ptrBackupQ = &queB;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        //默认BACKUP的那个queue是空的，所以先放它那边
        ptrBackupQ->push(x);
        while (!ptrMasterQ->empty())
        {
            //把当前所有master的中的值都弄到backup上
            ptrBackupQ->push(ptrMasterQ->front());
            ptrMasterQ->pop();
        }
        //把两个指针相互换一下位置
        queue<int> *tmp = ptrMasterQ;
        ptrMasterQ = ptrBackupQ;
        ptrBackupQ = tmp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = 0;
        //最好判断一下再调用POP
        if (!ptrMasterQ->empty())
        {
            ret = ptrMasterQ->front();
            ptrMasterQ->pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        
        //返回master的top
        if (!ptrMasterQ->empty())
        {
            return ptrMasterQ->front();
        }
        else
        {
            return 0;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return ptrMasterQ->empty();
    }
    
private:
    queue<int> *ptrMasterQ;
    queue<int> *ptrBackupQ;
    queue<int> queA;
    queue<int> queB;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */