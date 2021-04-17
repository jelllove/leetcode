/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, int> hashOrgNodeIndexPtr;//记录下所有的原来的节点的指针与index的关系
        vector<Node *> listNewNodePtr;//新的树的所有的节点
        
        Node *cur = head;
        Node node(0);//初始化一个点，这样可以避免在下面的while循环中少一个判断
        Node *tail = &node;
        
        int index = 0;
        while (cur != nullptr)
        {
            //记录下原始节点为的index
            hashOrgNodeIndexPtr[cur] = index++;
            //记录下原始节点与它的random节点的关系
            
            //开一个新的节点出来
            Node *newNode = new Node(cur->val);
            newNode->next = nullptr;
            tail->next = newNode; //先把这些NEW出来的节点串起来，先不管它们的random的值
            tail = newNode;
            listNewNodePtr.push_back(newNode);//然后按老的link一样的顺序把这些new的结点放到一个vector中
            cur = cur->next;
        }
        
        cur = head;
        index = 0;
        //重新遍历一次，这次是为了给new的节点把对应的random节点都加上值
        while (cur != nullptr)
        {
            
            if (cur->random == nullptr)
                listNewNodePtr[index]->random = nullptr;//如果原来的节点的random是空，那也一样
            else
                listNewNodePtr[index]->random = listNewNodePtr[hashOrgNodeIndexPtr[cur->random]];
                //上面这一句可能有一点绕，如果分开了写，就是：
                /*
                    int randomIndex = hashOrgNodeIndexPtr[orgRandomPtr]; //根据random节点的指针找出来原来对应的位置
                    Node *newRandomPtr = listNewNodePtr[randomIndex];//然后根据位置，再找出新的random的指针
                */
            ++index;
            cur = cur->next;                                           
        }
                                                           
        return node.next;
                                                           
    }
};