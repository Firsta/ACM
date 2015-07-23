class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                sta.push(i);
            else {
                if (sta.size() == 0) {
                    start = i + 1;
                } else {
                    if (sta.size() == 1)
                        ans = max(ans, i - start + 1);
                    else {
                        sta.pop();
                        ans = max(ans, i - sta.top());
                        continue;
                    }
                    sta.pop();
                }
            }
        }
        return ans;
    }
};
