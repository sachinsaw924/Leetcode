


//comparator logic thora nhi lagaya 
// use bad dekhte hai 

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
class Solution {
public:
       
    int maxLevelSum(TreeNode* root) {
          

         queue<TreeNode*> que;
         que.push(root);
          int levelNum = 1;
          int maxiSum = INT_MIN;
          int miniLevel = 0 ;
         while(!que.empty())
         {
            int n = que.size();
             
            long levelSum = 0 ;

            while(n--)
            {
                TreeNode* popNode = que.front();
                que.pop();
                levelSum += popNode -> val;

                if(popNode ->left != NULL)
                {
                    que.push(popNode -> left);
                }
                if(popNode -> right != NULL)
                {
                    que.push(popNode -> right);
                }
            }
             if(levelSum > maxiSum )
             {
                maxiSum = levelSum;
                miniLevel = levelNum;
             }
            levelNum++;
         }

      return miniLevel; 
    }
};
