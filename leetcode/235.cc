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
    TreeNode* ans;
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val < root->val && q->val < root->val)
            dfs(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            dfs(root->right, p, q);
        else
            ans = root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        dfs(root, p, q);
        return ans;
    }
};
