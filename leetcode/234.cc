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
    bool isPalindrome(ListNode* head) {
        int list_len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            list_len++;
            temp = temp->next;
        }
        if (list_len == 0 || list_len == 1)
            return true;
        ListNode *first_mid = head;
        for (int i = 0; i < list_len / 2 - 1; i++) {
            first_mid = first_mid->next;
        }
        ListNode *second_mid = first_mid->next;
        ListNode *former = NULL;
        ListNode *temp_mid = head;
        for (int i = 0; i < list_len / 2; i++) {
            ListNode *temp = temp_mid->next;
            temp_mid->next = former;
            former = temp_mid;
            temp_mid = temp;
        }
        if (list_len % 2 != 0) {
            second_mid = second_mid->next;
        }
        while (second_mid != NULL && first_mid != NULL) {
            if (second_mid->val != first_mid->val)
                return false;
            second_mid = second_mid->next;
            first_mid = first_mid->next;
        }
        return true;
    }
};
