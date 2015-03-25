class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m + n];
        int i = 0, j = 0;
        int cnt = 0;
        while (1) {
            if (i == m && j == n)
                break;
            else if (i == m) {
                while (j < n)
                    C[cnt++] = B[j++];
            } else if (j == n) {
                while (i < m)
                    C[cnt++] = A[i++];
            } else {
                if (A[i] <= B[j])
                    C[cnt++] = A[i++];
                else
                    C[cnt++] = B[j++];
            }
        }
        for (int i = 0; i < m + n; i++)
            A[i] = C[i];
    }
};
