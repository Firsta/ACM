/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

class Solution {
public:
    bool flag;
    int dfs(TreeNode *root) {
        if (root == NULL)
          return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (l - r > 1 || r - l > 1)
            flag = false;
       return max(l, r) + 1;
    }
    bool isBalanced(TreeNode *root) {
        flag = true;
        dfs(root);
        return flag;
    }
};
