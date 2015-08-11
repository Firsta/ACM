class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int ret = nums.size();
            int num = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i != 0 && nums[i] == nums[i - 1])
                    ret--;
                else
                    nums[num++] = nums[i];

            }
            return ret;

        }

};
