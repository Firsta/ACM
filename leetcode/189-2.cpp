class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        int *tmp = (int *) malloc (n*sizeof(int));
        for (int i = 0; i < n; i++)
            tmp[i] = nums[i];
        if (k == 0)
            return;
        for (int i = n - k, j = 0; j < n; i = (i+1) % n, j++)
            nums[j] = tmp[i];
    }
};
