

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
            priority_queue<int>pq;

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
