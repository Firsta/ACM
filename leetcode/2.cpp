class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p;
        p = l1;
        string ta;
        while (p != NULL) {
            ta = ta + (char)(p->val + '0');
            p = p->next;
        }
		long long a = 0;
		for (int i = ta.size() - 1; i >= 0; i--) {
			a = a * 10 + (int)(ta[i] - '0');
		}
        p = l2;
        string tb;
        while (p != NULL) {
            tb = tb + (char)(p->val + '0');
            p = p->next;
        }
		long long b = 0;
		for (int i = tb.size() - 1; i >= 0; i--) {
			b = b * 10 + (long long)(tb[i] - '0');
		}
        long long tmp = a + b;
		string sum;
        stringstream ss;
        ss << tmp;
        ss >> sum;
        p = NULL;
        for (long long i = 0; i < sum.size(); i++) {
            ListNode *tp;
            tp = (ListNode *)malloc(sizeof(struct ListNode));
            tp->next = p;
            tp->val = (long long)(sum[i] - '0');
            p = tp;
        }
        return p;
    }
};
