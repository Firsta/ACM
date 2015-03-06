/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode *no, int dep, int &ans){
    if (no->left == NULL && no->right == NULL) {
        ans = min(ans, dep);
        return;
    }
    if (no->left != NULL)
        dfs(no->left, dep+1, ans);
    if (no->right != NULL)
        dfs(no->right, dep+1, ans);
}

class Solution {
public:
    int minDepth(TreeNode *root) {
        int ans = INT_MAX;
        if (root == NULL)
            return 0;
        dfs(root, 1, ans);
        return ans;
    }
};
