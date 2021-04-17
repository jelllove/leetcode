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
    
    void linkTwoLink(Node *l1, Node *l2)
    {
        if (l1 == nullptr || l2 == nullptr)
            return;
        
        l1->next = l2;
        //l2->next = nullptr;//这步可以不要，因为看它的构造函数中，默认它的next = nullptr
        
        //这个可以这样递归，是因为它是一个完美二叉树，如果不是的话，就不能这样了
        linkTwoLink(l1->left, l1->right);
        linkTwoLink(l1->right, l2->left);
        linkTwoLink(l2->left, l2->right);
    }
    
    
    void dfs(Node *root, int level, unordered_map<int, Node *> &um)
    {
        if (root == nullptr)
            return;
        
        
        //前序遍历，或是中序遍历都是可以的，哪怕是后序都是可以的
        dfs(root->left, level + 1, um);
        dfs(root->right, level + 1, um);
        
        //root->next = nullptr;//这步可以不要，因为看它的构造函数中，默认它的next = nullptr
        
        if (um.count(level) == 0)
        {
            //如果是第一次
            um[level] = root;
        }
        else
        {
            um[level]->next = root;
            um[level] = root;
        }
        
    }
    
    Node* connect(Node* root) {
        
        //Method 1: BFS的方法，利用一个queue把这个树进行一个层遍历
        //这个方法好懂，但是没有按题目的要求，就是不能使用额外的空间
        /*
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
                
                if (n > 1)
                    node->next = q.front();
                
                --n;
            }
        }
        return root;
        */
        
        //Method 2: DFS的方法，借用了一个unordered_map来存下了第一层的最后一个结点的指针
        /*unordered_map<int, Node *> um;
        dfs(root, 0, um);
        
        return root;
        */
        
        //Method 3: DFS的方法，只要传入一个节点，然后把两个子结点相连，然后如此递归
        //但是没有按题目的要求，就是不能使用额外的空间
        /*
        if (root == nullptr)
            return nullptr;
        
        linkTwoLink(root->left, root->right);
        
        return root;
        */
        
        
        //Method 4: BFS的方法，这个也是最好的方法，又不要Recursion，又不要额外的空间
        if (root == nullptr)
            return nullptr;
        
        //pre只是为了能不改变root的指针的值
        Node *pre = root;
        
        //因为这个是一个完美二叉树，所以如果这下一层有东西，只要看它的左子树。
        while (pre->left != nullptr)
        {
            //用来遍历这一层的所有的结点
            Node *cur = pre;
        
            while (cur != nullptr)
            {
                //先把自己的两个子结点连起来
                cur->left->next = cur->right;
                
                //如果这个结点本来就有next的结点的话，那把自己的右节点指下下一个结点的左子树
                if (cur->next != nullptr)
                    cur->right->next = cur->next->left;
                
                //跳到下一个节点上
                cur = cur->next;
            }
            //找下一层
            pre = pre->left;
        }
        
        return root;
        
        
    }
};