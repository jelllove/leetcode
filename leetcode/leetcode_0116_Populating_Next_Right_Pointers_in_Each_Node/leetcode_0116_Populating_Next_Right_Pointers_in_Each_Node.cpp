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
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        queue<Node *> q;
        q.push(root);
        
        int n = 0;
        
        while (!q.empty())
        {
            n = q.size();
            
            while (n > 0)
            {
                Node *node = q.front();
                q.pop();
                
                if (node->left != nullptr)
                    q.push(node->left);
                
                if (node->right != nullptr)
                    q.push(node->right);
                
                if (n == 1)
                    node->next = nullptr;
                else
                    node->next = q.front();
                
                --n;
            }
        }
        return root;
    }
};