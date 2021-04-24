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
        if (root == NULL)
            return "NULL";
        
        return to_string(root->val) + " "s + serialize(root->left) + " "s + serialize(root->right);
    }

    TreeNode* generateTree(istringstream &is)
    {
        string s;
        is >> s;
        
        if (s == "NULL")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(s));
        
        node->left = generateTree(is);
        node->right = generateTree(is);
        
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "NULL")
            return nullptr;
        
        istringstream is(data);
        
        return generateTree(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;