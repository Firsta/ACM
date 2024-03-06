/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;
        if (head == NULL)
            return false;
        while (1) {
            if (p1->next == NULL)
                return false;
            else
                p1 = p1->next;
            if (p2->next == NULL)
                return false;
            else if (p2->next->next == NULL)
                return false;
            else
                p2 = p2->next->next;
            if (p1 == p2)
                return true;
        }
    }
};
