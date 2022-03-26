package heap

func swap(arr []int, idx1, idx2 int) {
	arr[idx1], arr[idx2] = arr[idx2], arr[idx1]
}
func heapInsert(arr []int, idx int) { //从idx开始向上调整为打根堆
	for arr[idx] >arr[(idx-1)/2] {
		swap(arr, idx, (idx-1)/2)
		idx = (idx-1)/2
	}
}

func heapify(arr []int, idx int) {
	left := 2 *idx +1
	for left < len(arr){
		right := 2*idx+2
		si := idx
		if  right < len(arr)  && arr[right] > arr[left]{
			si = right
		}else if arr[left] > arr[idx] {
			si = left
		}

		if si == idx {
			break
		}

		swap(arr, idx, si)
		left = si
	}
}

func heapSort(arr []int){
	for i := 0; i <len(arr); i++ {
		heapInsert(arr, i)
	}

	heapSize := len(arr)-1
	swap(arr, 0, heapSize)
	heapSize--

	for heapSize > 0 {
		heapify(arr, 0)
		swap(arr, 0, heapSize)
		heapSize--
	}
}
