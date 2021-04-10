/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


//之前使用class，也是可以的，但是使用class要比struct要慢一些
//估计是class中使用了默认构造函数
struct myCMP
{
public:
    bool operator () (const ListNode* a, const ListNode* b)
    {
        //这里返回值的意思的，这里和一般的lambda的比较式正好是相反的
        return (a->val > b->val);
    }
};



class Solution {
public:   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        //Method 1: using a while to go through all
        //一个个排序所有的list，然后每次遍历的时候都对刚找出来的元素进行一个排序
        /*
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        while (true)
        {
            vector<pair<int, ListNode *>> tmpVector;
            bool noNew = true;
            //这个存在重复遍历的问题
            for (int i = 0; i < lists.size(); ++i)
            {    
                if (lists[i] != NULL)
                {
                    tmpVector.push_back(make_pair(i, lists[i]));
                    noNew = false;
                }
            }
            
            if (noNew)
                break;
            
            
            std::sort(tmpVector.begin(), tmpVector.end(),
                     [](const pair<int, ListNode *> &a, const pair<int, ListNode *> &b){return a.second->val < b.second->val;});
            
            if (tail == NULL)
            {
                head = tmpVector[0].second;
            }
            else
            {
                tail->next = tmpVector[0].second;
            }
            tail = tmpVector[0].second;
            lists[tmpVector[0].first] = tmpVector[0].second->next;
            tail->next = NULL;
        }
        
        return head;
        */
        
        
        //Method 2: 使用最小堆，把所有的结节都放到最小堆中，然后利用它的自动排序，
        //最后一个个pop出来
        priority_queue<ListNode *, vector<ListNode *>, myCMP> pq;
        
        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode *node = lists[i];
            
            while (node != NULL)
            {
                pq.push(node);
                node = node->next;
            }
        }
        
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        while (!pq.empty())
        {
            if (tail == NULL)
                head = pq.top();
            else
                tail->next  = pq.top();
            
            tail = pq.top();
            tail->next = NULL;
            pq.pop();
        }
        
        return head;
        
    }
};