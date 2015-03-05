class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long tmp = n;
        long long x = 5;
        while (tmp >= x) {
            ans += tmp / x;
            x *= 5;
        }
        return ans;
    }
};
