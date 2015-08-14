class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool ans = true;
        int *mark1 = new int[257];
        int *mark2 = new int[257];
        for (int i = 0; i < 257; i++)
            mark1[i] = mark2[i] = 10000;
        for (int i = 0; i < s.size(); i++) {
            if (mark1[s[i]] == 10000 && mark2[t[i]] == 10000) {
                mark1[s[i]] = t[i];
                mark2[t[i]] = s[i];
            } else if (!(mark1[s[i]] == t[i] && mark2[t[i]] == s[i])) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
