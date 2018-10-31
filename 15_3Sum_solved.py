

class Solution:
	def threeSum(self, nums):
		'''
		: type nums: List[int]
		: rtype: List[List[int]]
		'''
		if len(nums) <= 2:
			return []

		result = []
		target = 0
		nums.sort()  # also needs sorting
		i = 0
		while i < len(nums)-2:
			j = i+1
			k = len(nums) -1
			while j < k:
				if nums[i] + nums[j] + nums[k] < target:
					j += 1
				elif nums[i] + nums[j] + nums[k] > target:
					k -= 1
				else:
					result.append(nums[i], nums[j], nums[k])
					j += 1
					k -= 1
					# avoid duplicates: 3 while loop
					while j < k and nums[j] == nums[j-1]:
						j += 1
					while j < k and nums[k] == nums[k+1]:
						k -= 1
			while i < len(nums) -2 and nums[i] == nums[i+1]:
				i += 1
			i += 1
		return result
