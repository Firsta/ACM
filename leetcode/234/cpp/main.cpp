/**
 * Definition for singly-linked list.
 */
#include <cassert>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        int len     = 0;
        while (p) {
            len++;
            p = p->next;
        }
        if (len == 1) {
            return true;
        }

        p = head;
        for (int i = 0; i < (len % 2 == 0 ? len / 2 : len / 2 + 1); i++) {
            p = p->next;
        }

        ListNode* right = p;
        // printf("%d\n", right->val);

        ListNode* pre = nullptr;

        p = head;
        for (int i = 0; i < len / 2; i++) {
            ListNode* t = p->next;
            p->next     = pre;
            pre         = p;
            p           = t;
        }

        p = pre;
        // printf("%d\n", p->val);
        for (int i = 0; i < len / 2; i++) {
            // printf("%d %d\n", p->val, right->val);
            if (p->val != right->val) {
                return false;
            }
            p     = p->next;
            right = right->next;
        }

        return true;
    }
};

int main() {
    ListNode* l = new ListNode(
        1, new ListNode(2, new ListNode(2, new ListNode(1, nullptr))));
    auto ret = Solution().isPalindrome(l);
    assert(ret == true);
}
