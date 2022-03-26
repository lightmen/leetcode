package merge

func mergeSort(arr []int) {
	merge(arr, 0, len(arr)-1)
}

func merge(arr []int, start, end int) {
	if end - start < 1 {
		return
	}

	mid := start + (end-start)>>1

	merge(arr, start, mid)
	merge(arr, mid+1, end)

	tmpArr := make([]int, end-start+1)
	l := start
	r := mid+1
	idx := 0
	for l <= mid && r <= end {
		if arr[l] < arr[r] {
			tmpArr[idx] = arr[l]
			l++
		}else {
			tmpArr[idx] = arr[r]
			r++
		}
		idx++
	}

	for l <= mid {
		tmpArr[idx] = arr[l]
		l++
		idx++
	}

	for r <= end {
		tmpArr[idx] = arr[r]
		r++
		idx++
	}

	for i := start; i <= end; i++ {
		arr[i] = tmpArr[i-start]
	}
}