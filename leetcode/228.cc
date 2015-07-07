class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int l = nums[0];
        vector<string> ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (l != nums[i - 1])
                    ans.push_back(to_string(l) + "->" + to_string(nums[i - 1]));
                else
                    ans.push_back(to_string(l));
                l = nums[i];
            }
        }
        return ans;
    }
};
