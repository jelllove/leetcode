/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    //Method 1: 先遍历，然后放到一个queue中，要的时候再去一个个pop出来
    /*
    void helper(TreeNode* root)
    {
        if (root == NULL)
            return;
        //遍历所有的，中序遍历
        helper(root->left);
        que.push(root->val);
        helper(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        
        if (root == NULL)
            return;
        helper(root);
    }
    
    int next() {
        int ret = que.front();
        que.pop();
        return ret;
    }
    
    bool hasNext() {
        return !que.empty();
    }
    
    
    queue<int> que;
    */
    
    
    //Method 2: 利用一个stack来完成
    //要先把所有的left节点放到stack中
    //然后一个个pop出来，在pop的时候，如果这个节点还有right节点的话
    //再重复放放它下面的所有left节点
    
    BSTIterator(TreeNode* root) {
        
        if (root == NULL)
            return;
        
        st.push(root);
        
        while (st.top()->left != NULL)
        {
            st.push(st.top()->left);
        }
    }
    
    int next() {
        //把当前TOP的节点拿出来
        TreeNode *top = st.top();
        st.pop();
        
        //如果这个节点有right节点的，放回到stack中，然后再找出所有的它的left节点
        if (top->right != NULL)
        {
            st.push(top->right);
            while (st.top()->left != NULL)
            {
                st.push(st.top()->left);
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    
    stack<TreeNode*> st;
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */