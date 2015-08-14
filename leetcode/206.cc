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
    ListNode * dfs(ListNode *pre, ListNode *now)
    {
        if (now == NULL)
            return now;
        if (now->next == NULL) {
            now->next = pre;
            return now;
        } else {
            ListNode * temp = dfs(now, now->next);
            now->next = pre;
            return temp;
        }
    }
    ListNode* reverseList(ListNode* head) {
        return dfs(NULL, head);
    }
};
