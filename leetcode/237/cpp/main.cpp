#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

void deleteNode(ListNode* node) {
    ListNode* p   = node;
    ListNode* pre = nullptr;
    while (p->next != nullptr) {
        p->val = p->next->val;
        pre    = p;
        p      = p->next;
    }
    pre->next = nullptr;
}

int main() {
    ListNode* l = new ListNode(
        4, new ListNode(5, new ListNode(1, new ListNode(9, nullptr))));
    ListNode* v = l->next->next;
    deleteNode(v);
    std::vector<int> vec;

    ListNode* p = l;
    while (p) {
        vec.push_back(p->val);
        p = p->next;
    }

    assert(vec == std::vector<int>({4, 5, 9}));
}