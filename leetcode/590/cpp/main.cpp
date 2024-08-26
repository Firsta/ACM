#include <cstdio>
#include <vector>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val      = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<int> postorder(Node* root) {
        vector<int> v;
        if (root != nullptr) {
            for (int i = 0; i < root->children.size(); i++) {
                vector<int> vv = postorder(root->children[i]);
                v.insert(v.end(), vv.begin(), vv.end());
            }
            v.push_back(root->val);
        }
        return v;
    }
};

int main() {
    Node* root = new Node(
        1,
        vector<Node*>({new Node(3, vector<Node*>({new Node(5), new Node(6)})),
                       new Node(2), new Node(4)}));

    Solution s;
    assert(s.postorder(root) == vector<int>({5, 6, 3, 2, 4, 1}));
}
