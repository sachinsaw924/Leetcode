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



// maza aaya 
// Revision mark : 0;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long,vector<long>,greater<long>>pq;
        queue<TreeNode*>que;

        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            long levelSum = 0 ;
            while(n--)
            {
             
                TreeNode* popNode = que.front();
                que.pop();
                levelSum += popNode->val;

                if(popNode -> left != NULL)
                {
                    que.push(popNode->left);
                }
                if(popNode -> right != NULL)
                {
                    que.push(popNode -> right);
                }
            }

            pq.push(levelSum);

            if(pq.size()>k)
            {
                pq.pop();
            }
        }


        return pq.size()<k  ? -1 : pq.top();
          

           
         




    }
};
