

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        int levelNum = 0;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            vector<TreeNode*> vec; // since yanah pointer le rhe hai to ye
                                   // directly change kr dega value ko

            while (n--) {
                TreeNode* levelValue = que.front();
                que.pop();
                vec.push_back(levelValue);

                if (levelValue->left != NULL) {
                    que.push(levelValue->left);
                }

                if (levelValue->right != NULL) {
                    que.push(levelValue->right);
                }
            }

            if (levelNum % 2 ==
                1) // odd wala level me sirf do bar visit kr rhe hai baki me ek
                   // bar visit kr rhe hai isliye iska time complexity hai O(n)
            // dusra space complexity bhi iska O(n) worst case me
            {

                int left = 0;
                int right = vec.size() - 1;

                while (left <= right) {
                    int temp = vec[left]->val;
                    vec[left]->val = vec[right]->val;
                    vec[right]->val = temp;
                    left++;
                    right--;
                }
            }

            levelNum++;
        }

        return root;
    }
};
