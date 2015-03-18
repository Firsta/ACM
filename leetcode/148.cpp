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
    ListNode *sortList(ListNode *head) {
        ListNode *ptr = head;
        vector<int> v;
        while (ptr != NULL) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(v.begin(), v.end());
        ptr = head;
        int i = 0;
        while (ptr != NULL) {
            ptr->val = v[i++];
            ptr = ptr->next;
        }
        return head;
    }
};
