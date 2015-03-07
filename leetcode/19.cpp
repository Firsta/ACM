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
    bool flag;
    int dfs(ListNode *root, int n)
    {
        if (root == NULL)
             return 0;
        int tmp = dfs(root->next, n) + 1;
        if (flag == true) {
            ListNode *tmp = root->next;
            root->next = tmp->next;
            tmp->next = NULL;
            flag = false;
        }
        if (tmp == n)
            flag = true;
        return tmp;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        flag = false;
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->next = head;
        dfs(tmp, n);
        return tmp->next;
    }
};
