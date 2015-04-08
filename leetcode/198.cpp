class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0)
            return 0;
        int *dp = new int[num.size() + 1];
        memset(dp, 0, sizeof(int) * (num.size() + 1));
        dp[1] = num[0];
        for (int i = 1; i < num.size(); i++)
            dp[i + 1] = max(dp[i - 1] + num[i], dp[i]);
        int ans = 0;
        for (int i = 1; i <= num.size(); i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};
