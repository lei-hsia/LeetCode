
# 15. 3Sum: failed: remove duplicates too far

class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <=2:
            return []
        if all([v==0 for v in nums]):
            return [[0,0,0]]
        list = []
        solution_list = []
        for i in range(len(nums)):
            target = 0 - nums[i]
            for j in nums[1:]:
                if target - nums[j] in list and nums[j] not in list:  
                    # target-nums[j]:存入list的确定的值; nums[j]:每次iteration变化的值
                    solution_list.append([ nums[i], target-nums[j], nums[j]])
                list.append(nums[j])
            return solution_list
        
        # Comment for line16: 
        # nums[j]是每次iteration变化的那个值
        # nums[j]本身不能也在list中!!!如果nums[j]在list中,两个值都在list中,说明之前已经append一次到solu_list中了,只是换了位置
        # 这种判断会误判一种情况: 后面两个值相等
