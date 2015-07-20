class Solution {
public:
    bool findp, findq;
    TreeNode *ans;
    bool dfs(TreeNode* now, TreeNode *p, vector<TreeNode*> &path) {
        if (now == NULL) {
            return false;
        }
        if (now == p) {
            path.push_back(now);
            return true;
        }
        if (dfs(now->left, p, path) || dfs(now->right, p, path)) {
            path.push_back(now);
            return true;
        } else
	    return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        dfs(root, p, p_path);
        dfs(root, q, q_path);
        TreeNode *ans = NULL;
        for (int i = p_path.size() - 1, j = q_path.size() - 1; i >= 0 && j >= 0; i--, j--) {
            if (p_path[i] == q_path[j])
                ans = p_path[i];
            else
                break;
        }
        return ans;
    }
};

