class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        if len(nums) == 0:
            return []
        nownum = nums[0]
        nowcnt = 1
        for i in range(1, len(nums)):
            if nowcnt == 0:
                nownum = nums[i]
                nowcnt = 1
            elif nownum != nums[i]:
                nowcnt -= 1
            else:
                nowcnt += 1
        return nownum
