package sum_of_subarray_minimums

func sumSubarrayMins(arr []int) int {
	st := make([]int, len(arr)) //单调递增栈
	left := make([]int, len(arr))
	right := make([]int, len(arr))

	top := -1
	for idx, val := range arr {
		for top > -1 && arr[st[top]] > val {
			top--
		}
		if top == -1 {
			left[idx] = -1
		}else {
			left[idx] = st[top]
		}
		top++
		st[top] = idx
	}

	top = -1
	for idx := len(arr)-1; idx >= 0; idx-- {
		for top > -1 && arr[st[top]] >= arr[idx] {
			top--
		}
		if top == -1 {
			right[idx] = len(arr)
		}else {
			right[idx] = st[top]
		}
		top++
		st[top] = idx
	}

	sum := 0
	const Mod = 1e9+7

	for idx := 0; idx < len(arr); idx++ {
		sum += (idx-left[idx]) * (right[idx] - idx) * arr[idx]
		sum %= Mod
	}


	return sum
}
