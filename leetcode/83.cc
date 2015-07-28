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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        if (head == NULL)
            return head;
        while (ptr->next != NULL) {
            if (ptr->val == ptr->next->val) {
                ListNode *temp = ptr->next;
                ptr->next = temp->next;
                temp->next = NULL;
                free(temp);
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};
