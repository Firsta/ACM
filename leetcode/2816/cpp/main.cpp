#include <cstdio>

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

ListNode* reverse(ListNode* head) {
    ListNode* r_head = nullptr;

    ListNode* pre = nullptr;
    ListNode* p   = head;
    while (p) {
        ListNode* t = p->next;
        if (!t) {
            r_head = p;
        }

        p->next = pre;
        pre     = p;
        p       = t;
    }

    return r_head;
}

ListNode* doubleIt(ListNode* head) {
    auto r_head = reverse(head);

    ListNode* p    = r_head;
    ListNode* last = nullptr;
    bool j         = false;
    while (p) {
        int t  = p->val * 2 + j;
        j      = (t >= 10);
        p->val = t % 10;

        if (!p->next) {
            last = p;
        }

        p = p->next;
    }
    if (j) {
        last->next = new ListNode(1, nullptr);
    }

    return reverse(r_head);
}

int main() {
    ListNode* l = new ListNode(9, new ListNode(9, new ListNode(9, nullptr)));
    l           = doubleIt(l);

    ListNode* p = l;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
}
