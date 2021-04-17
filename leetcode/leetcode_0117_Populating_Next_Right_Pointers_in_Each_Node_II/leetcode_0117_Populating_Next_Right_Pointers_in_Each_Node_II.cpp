/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    
    void bfsQueue(Node *root)
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);
        
        while (!q.empty())
        {
            int n = q.size();
            while (n > 0)
            {
                Node *node = q.front();
                q.pop();
                
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                
                if (n > 1)
                    node->next = q.front();
                
                --n;
            }
        }
    }
    
   
    
    void dfs(Node *root, int level, unordered_map<int, Node *> &um)
    {
        if (root == nullptr)
            return;
        
        dfs(root->left, level + 1, um);
        dfs(root->right, level + 1, um);
        
        if (um.count(level) == 0)
        {
            um[level] = root;
        }
        else
        {
            um[level]->next = root;
            um[level] = root;
        }
    }
    
    Node* connect(Node* root) {
        //Method 1: BFS,利用一个queue来辅助，好理解，但是不符合题目的要求
        /*
        bfsQueue(root);
        return root;
        */
        
        
        //Method 2: DFS,再外加一个unordered_map<int, Node*>来辅助
        /*
        unordered_map<int, Node *> um; // level + last Node ptr
        dfs(root, 0, um);
        return root;
        */
        
        //Method 3: 利用一个dummy的Node每次都指向每一行的头, 这个也是最好的方法了
        /*Node dummy(0);
        Node *cur = &dummy;
        Node *rec = root;
        
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                cur->next = root->left;
                cur = cur->next;
            }
            
            if (root->right != nullptr)
            {
                cur->next = root->right;
                cur = cur->next;
            }
            
            root = root->next;//在一行上行走
            if (root == nullptr)
            {
                //说明已经走到头了
                root = dummy.next;//刚才的第一个子结点
                dummy.next = nullptr;
                cur = &dummy;
            }
        }
        return rec;
        */
        //上面的Method 3的另一个写法，但是看上去效率没有使用了一个dummy后高
        Node *firstPtr = nullptr;
        Node *cur = nullptr;
        Node *rec = root;
        
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                if (firstPtr == nullptr)
                {
                    firstPtr = cur = root->left;
                }
                else
                {
                    cur->next = root->left;
                    cur = cur->next;   
                }
            }
            
            if (root->right != nullptr)
            {
                if (firstPtr == nullptr)
                {
                    firstPtr = cur = root->right;
                }
                else
                {
                    cur->next = root->right;
                    cur = cur->next;
                }
                
            }
            
            root = root->next;//在一行上行走
            if (root == nullptr)
            {
                //说明已经走到头了
                root = firstPtr;//刚才的第一个子结点
                firstPtr = nullptr;
                cur = nullptr;
            }
        }
        return rec;
    }
};