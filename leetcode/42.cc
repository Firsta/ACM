class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                left[i] = height[i];
            } else {
                left[i] = max(height[i], left[i - 1]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                right[i] = height[i];
            } else {
                right[i] = max(right[i + 1], height[i]);
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += min(left[i], right[i]) - height[i];
        }
        return ret;
    }
};
