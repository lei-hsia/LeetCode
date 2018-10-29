
'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict  ={}
        for index, value in enumerate(nums):
            # 值的判断
            if target - value in dict:
                # 之前存入的kv对, 根据value查找index, 而新的kv就是查找index
                return dict[target-value], index 
            # 因为要用enumerate中的一个查找另一个，所以存入dict的是value, 根据value查找index
            dict[value] = index
                