class Solution {
public:
    int maxProduct(int A[], int n) {
        vector<int> maxn, minn;
        maxn.push_back(1);
        minn.push_back(1);
        for (int i = 0; i < n; i++) {
            if (A[i] >= 0) {
                minn.push_back(min(A[i], A[i] * minn[i]));
                maxn.push_back(max(A[i], A[i] * maxn[i]));
            } else {
                minn.push_back(min(A[i], A[i] * maxn[i]));
                maxn.push_back(max(A[i], A[i] * minn[i]));
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
            ans = max(ans, maxn[i]);
        return ans;
    }
};
