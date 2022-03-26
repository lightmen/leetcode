package permutationii

func permuteUnique(nums []int) [][]int {
	arrList := make([][]int, 0)

	process(nums, 0, &arrList)
	return arrList
}

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func process(nums []int, i int, arrList *[][]int) {
	if i == len(nums)-1 {
		newNums := make([]int, len(nums))
		copy(newNums, nums)
		*arrList = append(*arrList, newNums)
		return
	}

	flag := make(map[int]struct{})
	for j := i; j < len(nums); j++ {
		if _, ok := flag[nums[j]]; ok {
			continue
		}

		flag[nums[j]] = struct{}{}
		swap(nums, i, j)
		process(nums, i+1, arrList)
		swap(nums, i, j)
	}
}
