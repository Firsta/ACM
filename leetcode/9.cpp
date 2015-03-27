class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int t1 = 0, t2;
        t2 = x;
        while (t2) {
            t1 = t1 * 10 + t2 % 10;
            t2 /= 10;
        }
        if (t1 == x)
            return true;
        else
            return false;
    }
};
