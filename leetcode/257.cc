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
    void dfs(TreeNode *root, vector<int> &path, vector<string> &ans) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->left != NULL)
            dfs(root->left, path, ans);
        if (root->right != NULL)
            dfs(root->right, path, ans);
        if (root->left == NULL && root->right == NULL) {
            string tmp;
            for (int i = 0; i < path.size(); i++) {
                tmp = tmp + to_string(path[i]);
                if (i != path.size() - 1)
                    tmp += "->";
            }
            ans.push_back(tmp);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ans;
        dfs(root, path, ans);
        return ans;
    }
};
