class Solution {
public:
    string minWindow(string s, string t) {
        int nozero = 0;
        int mark[256];
        int hash[256];
        memset(mark, 0, sizeof(mark));
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < t.size(); i++) {
            mark[(int)t[i]]++;
            hash[(int)t[i]] = 1;
        }
        for (int i = 0; i < 256; i++)
            if (mark[i])
                nozero++;
        int l = 0, r;
        int al, ar;
        int ans = s.size() + 1;
        for (r = 0; r < s.size(); r++) {
            if (hash[s[r]]) {
                mark[s[r]]--;
                if (!mark[s[r]])
                    nozero--;
            } else
                continue;
            if (!nozero) {
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    al = l;
                    ar = r;
                }
                while (l < r) {
                    if (hash[s[l]]) {
                        mark[s[l]]++;
                        if (mark[s[l]] > 0)
                            nozero++;
                    }
                    l++;
                    if (nozero)
                        break;
                    else {
                        if (r - l + 1 < ans) {
                            ans = r - l + 1;
                            al = l;
                            ar = r;
                        }
                    }
                }
            }
        }
        if (ans != s.size() + 1)
            return s.substr(al, ar - al + 1);
        else
            return "";
    }
};
