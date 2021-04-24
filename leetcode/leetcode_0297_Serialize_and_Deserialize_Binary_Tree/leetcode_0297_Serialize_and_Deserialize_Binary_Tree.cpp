/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "NULL";
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + " "s + left + " "s + right;
    }
    
    TreeNode* getTree(istringstream &is)
    {
        string str;
        is>>str;
        
        if (str == "NULL")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(str));
        node->left = getTree(is);
        node->right = getTree(is);
        
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "NULL" || data == "")
            return nullptr;
        
        istringstream is(data);
        return getTree(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));