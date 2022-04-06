package nextgreaterelementi

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	valMap := make(map[int]int)
	st := make([]int, len(nums2))
	top := -1

	for _, val := range nums2 {
		for top > -1 && val > st[top] {
			valMap[st[top]] = val
			top--
		}
		top++
		st[top] = val
	}

	for i := 0; i <= top; i++ {
		valMap[st[i]] = -1
	}

	arr := make([]int, len(nums1))
	for idx, val := range nums1 {
		arr[idx] = valMap[val]
	}

	return arr
}
