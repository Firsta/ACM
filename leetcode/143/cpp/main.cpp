#include <cstdio>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    } else {
        ListNode* pre = nullptr;
        ListNode* now = head;
        while (now != nullptr) {
            // printf("%d\n", now->val);
            ListNode* t = now->next;
            now->next   = pre;
            pre         = now;
            now         = t;
            // printf("%d\n", pre->val);
        }

        // printf("x\n");
        return pre;
    }
}

void reorderList(ListNode* head) {
    int len     = 0;
    ListNode* p = head;
    while (p) {
        len += 1;
        p = p->next;
    }

    ListNode* pre = nullptr;
    p             = head;
    for (int i = 0; i < (len % 2 == 0 ? len / 2 : len / 2 + 1); i++) {
        ListNode* t = p->next;
        pre         = p;
        p           = t;
    }
    // printf("%d\n", p->val);

    pre->next = nullptr;
    p         = reverseList(p);

    // printf("%d\n", p->val);

    ListNode* x = head;
    while (p && x) {
        ListNode* t  = x->next;
        ListNode* tt = p->next;
        x->next      = p;
        p->next      = t;
        x            = t;
        p            = tt;
    }
}

int main() {
    ListNode* l = new ListNode(
        1, new ListNode(
               2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    reorderList(l);
    vector<int> v;
    while (l) {
        v.push_back(l->val);
        l = l->next;
    }
    assert(v == vector<int>({1, 5, 2, 4, 3}));
}