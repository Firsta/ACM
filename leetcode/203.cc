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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ptr, *last;
        ptr = head;
        ListNode *temp = (ListNode *)(malloc(sizeof(ListNode)));
        temp->next = head;
        last = temp;
        ptr = head;
        while (ptr != NULL) {
            if (ptr->val == val) {
                last->next = ptr->next;
                free(ptr);
                ptr = last->next;
            } else {
                last = last->next;
                ptr = ptr->next;
            }
        }
        return temp->next;
    }
};
