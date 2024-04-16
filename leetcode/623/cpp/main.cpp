/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int now_depth, int dst_depth, int val) {
    if (root == nullptr) {
        return;
    }
    if (now_depth == dst_depth - 1) {
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->left  = new TreeNode(val, l, nullptr);
        root->right = new TreeNode(val, nullptr, r);
    } else {
        dfs(root->left, now_depth + 1, dst_depth, val);
        dfs(root->right, now_depth + 1, dst_depth, val);
    }
}

class Solution {
   public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val, root, nullptr);
            return new_root;
        } else {
            dfs(root, 1, depth, val);
            return root;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(
        4,
        new TreeNode(2, new TreeNode(3, nullptr, nullptr),
                     new TreeNode(1, nullptr, nullptr)),
        new TreeNode(6, new TreeNode(5, nullptr, nullptr), nullptr));
    Solution s;
    s.addOneRow(root, 1, 2);
}
