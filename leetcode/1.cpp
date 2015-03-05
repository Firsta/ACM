class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        map<int, int> mm;
        for (int i = 0; i < n; i++) {
            if (mm[target - numbers[i]]) {
                ans.push_back(mm[target - numbers[i]]);
                ans.push_back(i + 1);
                return ans;
            }
            mm[numbers[i]] = i + 1;
        }
        return ans;
    }
};
