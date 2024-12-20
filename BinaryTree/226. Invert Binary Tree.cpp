
class Solution {
public:
   void swap(TreeNode* root)
   {
    if(!root)
    {
        return ;
    }

    TreeNode* temp = root->left;
    root->left = root ->right;
    root -> right = temp;
    swap(root->left);
    swap(root->right);
   }
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root ;
    }
};
