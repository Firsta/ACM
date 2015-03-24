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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        if (ptr1 == NULL || ptr2 == NULL)
            return NULL;
        int lena = 0, lenb = 0;
        while (ptr1 != NULL) {
            ptr1 = ptr1->next;
            lena++;
        }
        while (ptr2 != NULL) {
            ptr2 = ptr2->next;
            lenb++;
        }
        
        int tmp;
        ptr1 = headA; ptr2 = headB;
        if (lena > lenb) {
            tmp = lena - lenb;
            while (tmp--)
                ptr1 = ptr1->next;
        } else {
            tmp = lenb - lena;
            while (tmp--)
                ptr2 = ptr2->next;
        }
        
        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1 == ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};
