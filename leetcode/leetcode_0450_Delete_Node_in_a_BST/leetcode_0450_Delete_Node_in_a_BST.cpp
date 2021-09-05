TreeNode* deleteNode(TreeNode* root, int x) {      
	
	if(root == NULL)
        
		return NULL;
   
   if(root->val == x)
   
   {
        
		TreeNode *s=root->right;

        if(s==NULL)
            return root->left;

        while(s->left !=NULL)
            s=s->left;

        root->val =s->val;

        root->right = deleteNode(root->right,s->val);
    }
    else if(root->val > x)
    {
        root->left=deleteNode(root->left,x);
    }
    else
        root->right=deleteNode(root->right,x);
    return root;
}