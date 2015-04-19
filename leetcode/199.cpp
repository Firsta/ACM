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
    int maxd;
    vector<int> ans;
    void dfs1(TreeNode *p, int dep)
    {
        maxd = max(maxd, dep);
        if (p->left != NULL)
            dfs1(p->left, dep + 1);
        if (p->right != NULL)
            dfs1(p->right, dep + 1);
    }
    void dfs2(TreeNode *p, int dep)
    {
        ans[dep] = p->val;
        if (p->left != NULL)
            dfs2(p->left, dep + 1);
        if (p->right != NULL)
            dfs2(p->right, dep + 1);
    }
    vector<int> rightSideView(TreeNode *root) {
        if (root == NULL)
            return ans;
        maxd = 0;
        dfs1(root, 1);
        for (int i = 0; i < maxd; i++)
            ans.push_back(0);
        dfs2(root, 0);
        return ans;
    }
};
