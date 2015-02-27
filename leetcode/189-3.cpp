class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        int *tmp = (int *) malloc (n*sizeof(int));
        for (int i = 0; i < n; i++)
            tmp[i] = nums[i];
        for (int i = 0; i < k; i++)
            nums[i] = tmp[n - k + i];
        for (int i = k; i < n; i++)
            nums[i] = tmp[i - k];
    }
};
