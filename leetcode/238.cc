class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all = 1;
        int zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                all *= nums[i];
            else
                zero++;
        }
        vector<int> ans;
        if (zero >= 2) {
            for (int i = 0; i < nums.size(); i++)
                ans.push_back(0);
            return ans;
        } else if (zero == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0)
                    ans.push_back(0);
                else
                    ans.push_back(all);
            }
            return ans;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back(all / nums[i]);
            }
        }
    }
};
