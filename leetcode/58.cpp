class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ans = 0;
        int mark = 0;
        const char *p = s;
        while (1) {
            if ((*p) == '\0')
                break;
            else if ((*p) == ' ') {
                mark = 1;
            } else {
                if (mark == 1) {
                    ans = 0;
                    mark = 0;
                }
                ans++;
            }
            p++;
        }
        return ans;
    }
};
