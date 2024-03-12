#include <stdio.h>

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

class Solution {
   public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* p   = head;
        ListNode* pre = dummy;

        while (p) {
            int sum      = 0;
            ListNode* pp = p;

            bool found = false;
            while (pp) {
                // printf("%d\n", sum);
                sum += pp->val;
                if (sum == 0) {
                    found = true;
                    break;
                }
                pp = pp->next;
            }

            if (!found) {
                pre = p;
                p   = p->next;
            } else {
                pre->next = pp->next;
                p         = pp->next;
            }
        }

        return dummy->next;
    }
};

int main() {
    ListNode* l = new ListNode(
        1, new ListNode(
               2, new ListNode(-3, new ListNode(3, new ListNode(1, nullptr)))));
    Solution s;
    ListNode* p = s.removeZeroSumSublists(l);

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
}