package heap

func handleHeap(arr []int, idx int) {
	for arr[idx] > arr[(idx-1)/2] {
		parent := (idx - 1) / 2
		arr[idx], arr[parent] = arr[parent], arr[idx]
		idx = parent
	}
}

func buildHeap(arr []int) {
	for i := 0; i < len(arr); i++ {
		handleHeap(arr, i)
	}
}

func sortHead(arr []int, heapSize int) {
	parent := 0
	for {
		idx := 2*parent + 1
		if idx >= heapSize {
			return
		}
		right := 2*parent + 2
		if right < heapSize && arr[right] > arr[idx] {
			idx = right
		}

		if arr[parent] > arr[idx] {
			return
		}

		arr[parent], arr[idx] = arr[idx], arr[parent]
		parent = idx
	}
}

func sort(arr []int) {
	buildHeap(arr)

	for i := len(arr) - 1; i > 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		sortHead(arr, i)
	}
}
