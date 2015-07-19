class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int s = nums.size() - k + 1;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if (q.size() > s)
                q.pop();
        }
        return q.top();
    }
};
