class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        dic = {}
        for index, val in enumerate(nums):
            if val in dic:
                if index - dic[val] <= k:
                    return True
            dic[val] = index
        return False
