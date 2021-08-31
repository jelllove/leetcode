 priority_queue<double>pq1;
    priority_queue<double,vector<double>,greater<double>>pq2;
    MedianFinder() {     
    }
    void addNum(int num) {
      if(pq2.size()>0&&num>pq2.top())
        {
            pq2.push(num);
        }
        else
        {
            pq1.push(num);
        }
        if(pq2.size()>pq1.size())
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
        if(pq1.size()-pq2.size()>1)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    double findMedian() {
        if(pq1.size()==pq2.size())
        {
            return (pq1.top()+pq2.top())/2;
        }
        return pq1.top();
    }