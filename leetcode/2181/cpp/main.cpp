#include <assert.h>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeNodes(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        } else {
            ListNode* t = head->next;
            while (t->val != 0) {
                head->val += t->val;
                t = t->next;
            }
            head->next = mergeNodes(t);
            return head;
        }
    }
};

int main() {
    ListNode* head = new ListNode(
        0,
        new ListNode(
            3,
            new ListNode(
                1, new ListNode(
                       0, new ListNode(
                              4, new ListNode(
                                     5, new ListNode(2, new ListNode(0))))))));
    head = Solution().mergeNodes(head);
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    assert(v == vector<int>({4, 11}));
}
