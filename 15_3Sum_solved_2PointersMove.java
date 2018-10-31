
// 用到了 TwoSum的思想; 

/*
	难得想的地方：首先给nums排序!!!
	这样固定第一个数之后，后面两个数可以用两个指针，一个指向头一个指向尾
	同时向中间移动(类似于quicksort的思想，多用)

	保证不加入重复的list: 因为nums是有序的，所以

	1. 找到一组之后，当前指针一定要移动到和当前元素不同的地方: 
	判断: nums[i] != nums[i-1]; 这是针对固定的那个element

	2. 后面两个滑动的元素指针在便利数组的时候，虽然方向不同，但是
	如果和上一个元素相同，那么也要继续后移 

*/ 

// List<Type> : define a list w. confined generics Type
/*
	here, define a list of type list which stores integers,
	dynamically initialize it as LinkedList because the 
	add method built-in in LinkedList is easy to use
*/
public List<List<Integer>> 3Sum(int[] nums){
	Arrays.sort(nums);  // SORT this list!!
	List<List<Integer>> solution = new LinkedList();

	for(int i=0; i<nums.length-2; i++){
		// 每次新的固定的第一个元素不能和上次的相同
		if (i==0 || i>0 && nums[i] != nums[i-1]){
			// 2 pointers, 1 starts from i+1, one from end
			int p1 = i+1, p2 = nums.length-1;
			int sum = 0 - nums[i];
			while(p1 < p2){
				if(nums[p1]+nums[p2] == sum){
					solution.add(Arrays.asList(nums[i], nums[p1], nums[p2]));
					// 指针如果指向相同的元素，也要移向下一个元素
					while(p1 < p2 && nums[p1] == nums[p1+1]) p1++;
					while(p1 < p2 && nums[p2] == nums[p2-1]) p2--;
					// if not, then it's normal: p1++, p2--
					p1++; 
					p2--;
				}
				else if(nums[p1] + nums[p2] < sum) pi++;
				else p2--;
			}
		}
	}

	return solution; 
}