#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) {
    vector<int> vals;
    ListNode* p = head;
    while (p) {
        vals.push_back(p->val);
        p = p->next;
    }

    int n = vals.size();
    vector<bool> del(n, true);
    int mmax = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (vals[i] >= mmax) {
            del[i] = false;
            mmax   = vals[i];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     printf("%s ", del[i]?"true":"false");
    // }
    // printf("\n");

    ListNode* t = new ListNode(0, head);

    ListNode* pre = t;
    p             = head;
    int i         = 0;

    while (p) {
        // printf("%d\n", p->val);
        if (del[i]) {
            // printf("del\n");
            pre->next = p->next;
        } else {
            // printf("no del\n");
            pre = p;
        }
        p = p->next;
        i++;
    }

    return t->next;
}

int main() {
    ListNode* l = new ListNode(
        5, new ListNode(
               2, new ListNode(13, new ListNode(3, new ListNode(8, nullptr)))));
    auto x = removeNodes(l);
    while (x) {
        printf("%d ", x->val);
        x = x->next;
    }
}