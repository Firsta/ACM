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

int main() {
    ListNode* l = new ListNode(0, new ListNode(1, nullptr));
    l           = reverseList(l);
    vector<int> v;
    while (l) {
        v.push_back(l->val);
        l = l->next;
    }
    assert(v == vector<int>({1, 0}));
}
