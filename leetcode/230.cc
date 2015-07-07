/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum, ans;
    void dfs(TreeNode* root) {
        if (root->left != NULL) {
            dfs(root->left);
        }
        sum--;
        if (sum == 0)
            ans = root->val;
        if (root->right != NULL)
            dfs(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        sum = k;
        dfs(root);
        return ans;
    }
};
