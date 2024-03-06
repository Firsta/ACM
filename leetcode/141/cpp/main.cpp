#include <cassert>
#include <cstdlib>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (head) {
            ListNode *n1 = head;
            ListNode *n2 = head->next;

            if (n2 == NULL) {
                return false;
            }

            while (n1 && n2) {
                n1 = n1->next;
                if (n2->next == NULL) {
                    return false;
                } else {
                    n2 = n2->next->next;
                    if (n1 == n2) {
                        return true;
                    }
                }
            }

            return false;
        } else {
            return false;
        }
    }
};

int main() {
    ListNode *h   = new ListNode(1);
    h->next       = new ListNode(2);
    h->next->next = h;

    Solution *x = new Solution();
    assert(x->hasCycle(h) == true);
}
