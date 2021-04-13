/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* generateGraph(unordered_map<int, Node *> &existNode, Node *node)
    {
        //如果这个结点已经生成过了，那就直接返回
        if (existNode.count(node->val) > 0)
            return existNode[node->val];

        //如果这个值是第一次，那就NEW一个出来
        Node *newNode = new Node(node->val);
        //然后记录下来
        existNode[node->val] = newNode;
        
        //再遍历这个node的所有neighbors
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            Node *nbNode = generateGraph(existNode, node->neighbors[i]);
            if (nbNode != NULL)
            {
                newNode->neighbors.push_back(nbNode);
            }
        }
        
        return newNode;
        
    }
    
    
    Node* cloneGraph(Node* node) {
        
        
        if (node == NULL)
            return NULL;
        unordered_map<int, Node *> existNode;
        
        //Method 1: Recursion, DFS method
        /*return generateGraph(existNode, node);*/
        
        //Method 2: No Recursion, BFS, using the queue
        queue<Node *> q;
        q.push(node);
        
        int n = 0;
        int i = 0;
        while (!q.empty())
        {
            n = q.size();
            
            for (int i = 0; i < n; ++i)
            {
                Node *cur = q.front();
                q.pop();
                
                if (existNode.count(cur->val) >= 1)
                {
                    continue;
                }
                
                Node *newNode = new Node(cur->val);
                existNode[cur->val] = newNode;
                
                
                for (auto &n : cur->neighbors)
                {
                    if (existNode.count(n->val) >= 1)
                    {
                        Node *tmp = existNode[n->val];
                        newNode->neighbors.push_back(tmp);
                        tmp->neighbors.push_back(newNode);
                    }
                    else
                    {
                        q.push(n);    
                    }
                }
            }
        }
        
        return existNode[node->val];
        
    }
};