class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1])
                x = i;
        }
        if (x == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int y;
        for (int i = nums.size() - 1; i >= x + 1; i--) {
            if (nums[i] > nums[x]) {
                y = i;
                break;
            }
        }
        swap(nums[x], nums[y]);
        reverse(nums.begin() + x + 1, nums.end());
    }
};
