/**
 * Definition for a binary tree node.
 */
#include <cassert>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *root, int target) {
    bool delete_left  = false;
    bool delete_right = false;

    if (root->left) {
        delete_left = dfs(root->left, target);
        if (delete_left) {
            root->left = nullptr;
        }
    }

    if (root->right) {
        bool delete_right = dfs(root->right, target);
        if (delete_right) {
            root->right = nullptr;
        }
    }

    bool ret = (!root->left || delete_left) && (!root->right || delete_right) &&
               root->val == target;
    // printf("%d %d\n", root->val, ret);
    return ret;
}

class Solution {
   public:
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        auto delete_root = dfs(root, target);
        return delete_root ? nullptr : root;
    }
};

void dfs_show(TreeNode *root, std::vector<int> &v) {
    if (!root) {
        return;
    } else {
        dfs_show(root->left, v);
        v.push_back(root->val);
        dfs_show(root->right, v);
    }
}

int main() {
    TreeNode *root = new TreeNode(
        1, new TreeNode(2, new TreeNode(2, nullptr, nullptr), nullptr),
        new TreeNode(3, new TreeNode(2, nullptr, nullptr),
                     new TreeNode(4, nullptr, nullptr)));
    root = Solution().removeLeafNodes(root, 2);

    std::vector<int> v;
    dfs_show(root, v);

    assert(v == std::vector<int>({1, 3, 4}));

    return 0;
}
