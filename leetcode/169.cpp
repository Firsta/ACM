class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> mm;
        int n = num.size();
        for (int i = 0; i < num.size(); i++) {
            if (++mm[num[i]] > n / 2)
                return num[i];
        }
    }
};
