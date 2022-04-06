package dailytemperatures

func dailyTemperatures(temperatures []int) (arr []int) {
	st := make([]int, len(temperatures))
	top := -1

	arr = make([]int, len(temperatures))

	for idx, val := range temperatures {
		for top > -1 && val > temperatures[st[top]] {
			arr[st[top]] = idx - st[top]
			top--
		}
		top++
		st[top] = idx
	}

	for top > -1 {
		arr[st[top]] = 0
		top--
	}

	return
}
