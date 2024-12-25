

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int>ans;
        que.push(root);
        if(root==nullptr)
        {
            return ans;
        }

        while(!que.empty())
        {
            int n = que.size();
            priority_queue<int>pq; // yanha pr hum int maxEl = INT_MIN bhi to use kr skte hai

            while(n--)
            {
                TreeNode* nodeValue = que.front();
                que.pop();
                pq.push(nodeValue->val);
                if(nodeValue->left != NULL)
                {
                    que.push(nodeValue->left);
                }
                if(nodeValue ->right != NULL)
                {
                    que.push(nodeValue ->right);
                }
            }
            if(!pq.empty())
            {
                ans.push_back(pq.top());

            } 
        }
        return ans ;
    }
};






//    BOHUT SARA QUESTION BAN JATA HAI IS TECHINQUE SE DHAYA RAKHNA EK BAR DRY RUN KR LENA ISKO APNE SE 





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
   void solve(TreeNode* root ,int depth, vector<int>&ans)
   {
    if(root == nullptr)
    {
         return ;
    }

    if(ans.size()==depth)
    {
        ans.push_back(root->val);
    }
    else
    {
        ans[depth] = max(ans[depth],root->val);
    }

    solve(root->left,depth+1,ans);
    solve(root->right,depth+1,ans);
    


   }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr)
        {
            return ans ;
        }
         solve(root,0,ans);
         return ans;

    }
};
