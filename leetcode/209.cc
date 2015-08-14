class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = nums.size() + 1;
        if (ans == 1)
            return 0;
        int len = 0;
        int sum = 0;
        int l = 0, r = 0;
        for (r = 0; r < nums.size(); r++) {
            sum += nums[r];
            if (sum >= s) {
                ans = min(ans, r - l + 1);
                while (l < r) {
                    sum = sum - nums[l];
                    l++;
                    if (sum >= s)
                        ans = min(ans, r - l + 1);
                    else
                        break;
                }
            }
        }
        if (ans == nums.size() + 1)
            return 0;
        else
            return ans;
    }
};
