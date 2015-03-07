class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans;
        if (strs.size() == 0)
            return ans;
        for (int i = 0; ; i++) {
            bool flag = false;
            if (i >= strs[0].size())
                break;
            char tmp = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() <= i) {
                    flag = true;
                    break;
                }
                if (strs[j][i] != tmp) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            else
                ans = ans + tmp;
        }
        return ans;
    }
};
