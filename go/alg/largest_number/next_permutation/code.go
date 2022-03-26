package nextpermutation

func reverse(nums []int, i, j int) {
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}

func nextPermutation(nums []int) {
	idx := len(nums) - 1

	for ; idx > 0; idx-- {
		if nums[idx-1] < nums[idx] {
			break
		}
	}

	if idx <= 0 {
		reverse(nums, 0, len(nums)-1)
		return
	}

	for i := len(nums) - 1; i >= idx; i-- {
		if nums[i] > nums[idx-1] {
			nums[idx-1], nums[i] = nums[i], nums[idx-1]
			break
		}
	}

	reverse(nums, idx, len(nums)-1)
	return
}
