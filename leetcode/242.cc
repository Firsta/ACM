class Solution {
public:
    bool isAnagram(string s, string t) {
        char p1[26], p2[26];
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        for (const auto &ch : s)
            p1[ch - 'a']++;
        for (const auto &ch : t)
            p2[ch - 'a']++;
        for (int i = 0; i < 26; i++)
            if (p1[i] != p2[i])
                return false;
        return true;
    }
};
