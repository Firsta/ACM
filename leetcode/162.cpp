class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (num[i] > num[i + 1])
                    return i;
            } else if (i == n - 1) {
                if (num[i] > num[i - 1])
                    return i;
            }else if (num[i] > num[i - 1] && num[i] > num[i + 1])
                return i;
        }
        return 0;
    }
};
