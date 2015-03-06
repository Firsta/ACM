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
    vector<int> tmp;
    vector<vector<int>> ans;
    
    void dfs(TreeNode *root, int sum)
    {
        sum -= root->val;
        tmp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) {
                ans.push_back(tmp);
            }
        }
        if (root->left != NULL)
            dfs(root->left, sum);
        if (root->right != NULL)
            dfs(root->right, sum);
        tmp.erase(tmp.end() - 1);
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return ans;
        dfs(root, sum);
        return ans;
    }
};
