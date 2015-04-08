class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        bool *ch = new bool[500];
        for (int i = 0; i < 500; i++)
            ch[i] = false;
        int l = 0, r = 0;
        ch[(int)(s[0] - '0')] = true;
        int maxlen = 1;
        while (true) {
            r++;
            if (r >= s.size())
                break;
            while (ch[(int)(s[r] - '0')] && l < r) {
                ch[(int)(s[l] - '0')] = false;
                l++;
            }
            ch[(int)(s[r] - '0')] = true;
            if (r - l + 1 > maxlen)
                maxlen = r - l + 1;
        }
        return maxlen;
    }
};
