class Solution {
public:
    int atoi(string str) {
        bool flagz = false, flagf = false, flagn = false;
        long long ans = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-') {
                if (flagz || flagf)
                    return 0;
                flagf = true;
                flagn = true;
            } else if (str[i] == '+') {
                if (flagf || flagz)
                    return 0;
                flagz = true;
                flagn = true;
            } else if (str[i] == ' ') {
                if (flagn == false)
                    continue;
                break;
            } else if (str[i] < '0' || str[i] > '9') {
                break;
            } else {
                ans = ans * 10 + (int)(str[i] - '0');
                if (ans > INT_MAX || (-ans) < INT_MIN)
                    break;
                flagn = true;
            }
        }
        if (flagf)
            ans = -ans;
        if (ans > INT_MAX)
            ans = INT_MAX;
        if (ans < INT_MIN)
            ans = INT_MIN;
        return ans;
    }
};
