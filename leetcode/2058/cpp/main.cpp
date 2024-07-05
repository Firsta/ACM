#include <assert.h>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int first         = -1;
        int last_critical = -1;

        int max = head->val;
        int min = head->val;

        int last_node_val = head->val;
        head              = head->next;
        int count         = 1;
        int critical_cnt  = 0;

        int min_distance = 100001;
        while (head) {
            if (head->next) {
                bool critical =
                    (head->val > last_node_val &&
                     head->val > head->next->val) ||
                    (head->val < last_node_val && head->val < head->next->val);
                if (critical) {
                    critical_cnt += 1;
                    if (first == -1) {
                        first = count;
                    }
                    if (last_critical != -1) {
                        min_distance =
                            std::min(min_distance, count - last_critical);
                    }
                    last_critical = count;
                }
            }
            count += 1;
            last_node_val = head->val;
            head          = head->next;
        }

        if (critical_cnt <= 1) {
            return vector<int>({-1, -1});
        } else {
            return vector<int>({min_distance, last_critical - first});
        }
    }
};

int main() {
    ListNode *head = new ListNode(
        5,
        new ListNode(
            3,
            new ListNode(
                1, new ListNode(
                       2, new ListNode(
                              5, new ListNode(1, new ListNode(2, nullptr)))))));
    assert(Solution().nodesBetweenCriticalPoints(head) == vector<int>({1, 3}));
    return 0;
}