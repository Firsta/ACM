class Solution {
public:
    int cal(int x) {
        int res = 0;
        while (x) {
            int tmp = x % 10;
            res += tmp * tmp;
            x /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int one, two;
        one = two = n;
        do {
            one = cal(one);
            two = cal(two);
            two = cal(two);
        } while (two != 1 && one != two);

        if (two == 1)
            return true;
        else
            return false;
    }
};
