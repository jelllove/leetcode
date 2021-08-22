class Solution {
    public:
    vector<pair<TreeNode*,TreeNode*>> vec; // To store pairs that violates BST  
    TreeNode* prev = NULL; // keep track of previous node
    
    void solve(TreeNode* root)
    {
        if(root == NULL)  return; // Base Condition
        
        solve(root->left); // First left
        // Than deal with Val 
        
        /* if statement says : if previous node exists and previous node has a value more than next or any root that comes to the 
		right of prev than	in such case it violates BST condition so push that pair in vec for now, will deal withit later */
        if(prev && prev->val > root->val) vec.push_back({prev,root}); 
        
        prev = root; // keep updating prev, for checking BST condition further
        solve(root->right); // At last right, this is inorder manner
    }
    
    void recoverTree(TreeNode* root) 
    {    
        solve(root); // Inorder traversal
        
        /* If just 2 adjacent nodes violated BST , than there will be 1 key value pair in           
		vec and we will swap it and problem is solved */
        if(vec.size() == 1) 
            swap(vec[0].first->val, vec[0].second->val);
        
        /* We know its given in question that only 2 nodes of the tree were swapped, but what if those 2 nodes are not adjacent, in that case 
		we have 2 key value pairs which shows there is irregularity in 4 elements. (so size of vec is 2). eg: 1 2 3 4 , we change it to : 4 2 3 1 
		which leads to inconsistency in {4,2} and {3,1} so to solve it we swap first of 0th and second of 1th which are 4 and 1 respectively, 
		we can get 1 2 3 4 back, same is done below : */
        if(vec.size() == 2)
            swap(vec[0].first->val, vec[1].second->val);
    }
};
