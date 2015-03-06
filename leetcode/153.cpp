class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        for (int i = 0; i < n - 1; i++)
            if (num[i] > num[i + 1]) {
                return num[i + 1];
            }
        return num[0];
    }
};
