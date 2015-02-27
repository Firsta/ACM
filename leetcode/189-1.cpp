class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        int i = 0, j = n - 1;
        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;j--;
        }
        i = 0;j = k - 1;
        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;j--;
        }
        i = k;j = n - 1;
        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;j--;
        }
    }
};
