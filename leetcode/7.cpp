class Solution {
public:
    int reverse(int x) {
        long long num = x;
        int flag = 0;
        if (num < 0) {
            num = -num;
            flag = 1;
        }
        long long ans = 0;
        while (num) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        if (flag)
            ans = -ans;
        if (ans > INT_MAX)
            return 0;
        if (ans < INT_MIN)
            return 0;
        return ans;
    }
};
