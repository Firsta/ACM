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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1;

        ListNode* p1 = nullptr;
        for (int i = 0; i < a - 1; i++) {
            p = p->next;
        }
        p1 = p;

        ListNode* p2 = nullptr;
        for (int i = 0; i < b - a + 2; i++) {
            p = p->next;
        }
        p2 = p;

        p1->next = list2;

        p = list2;
        while (p->next) {
            p = p->next;
        }

        p->next = p2;

        return list1;
    }
};

int main() {
    auto list1 = new ListNode(
        10, new ListNode(
                1, new ListNode(
                       13, new ListNode(
                               6, new ListNode(9, new ListNode(5, nullptr))))));
    auto list2 = new ListNode(
        1000000, new ListNode(1000001, new ListNode(1000002, nullptr)));
    auto ret = Solution().mergeInBetween(list1, 3, 4, list2);

    vector<int> v;
    while (ret) {
        v.push_back(ret->val);
        ret = ret->next;
    }

    assert(v == vector<int>({10, 1, 13, 1000000, 1000001, 1000002, 5}));
}
