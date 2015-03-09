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
    void dfs(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return;
        else if (!(p != NULL && q != NULL)) {
            flag = false;
            return;
        }
        if (p->val != q->val) {
            flag = false;
            return;
        }
        if (p->left != NULL && q->left != NULL)
            dfs(p->left, q->left);
        else if (!(p->left == NULL && q->left == NULL)) {
            flag = false;
            return;
        }
        if (p->right != NULL && q->right != NULL)
            dfs(p->right, q->right);
        else if (!(p->right == NULL && q->right == NULL)) {
            flag = false;
            return;
        }
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        flag = true;
        dfs(p, q);
        if (flag)
            return true;
        else
            return false;
    }
};
