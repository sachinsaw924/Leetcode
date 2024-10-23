


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

//T.C O(2n)
// s.c O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {



        // doing bfs together 

       if(root == NULL)
       {
        return root;
       } 
       queue<TreeNode*>que;
       vector<int>levelSum;
       que.push(root);

       while(!que.empty())
       {

        int levelSum1 = 0 ;
        int n = que.size();
        while(n--) 
        {
         TreeNode* levelValue = que.front();
         que.pop();
         levelSum1 += levelValue -> val;
         if(levelValue -> left != NULL)
         {
            que.push(levelValue->left);
         }
         if(levelValue -> right != NULL)
         {
            que.push(levelValue -> right);
         }
        }
        levelSum .push_back(levelSum1);
     }

      //  step 2 finding sibiling sum which i could not understand 
      que.push(root);
      root -> val = 0;
      int i = 1 ;
      while(!que.empty())
      {
        int n = que.size();
        while(n--)
        {
            TreeNode* curr = que.front();
            que.pop();
            int sibilingSum = curr->left != NULL ? curr -> left -> val : 0;
             sibilingSum += curr -> right != NULL ? curr -> right -> val : 0;

             if(curr -> left )
             {
                curr -> left -> val = levelSum[i]-sibilingSum;
                que.push(curr-> left);
             }
             if(curr -> right)
             {
                curr -> right -> val = levelSum[i]-sibilingSum;
                que.push(curr -> right);
             }
        }
        i++;
      }

        return root;
    }
};



