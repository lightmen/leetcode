package sortanarray

import "testing"

func TestSort(t *testing.T) {
	arr := []int{23, 5, 98, 60, 23, 134}
	sortArray(arr)
	t.Logf("%v", arr)

	arr = []int{1, 2, 3, 4}
	sortArray(arr)
	t.Logf("%v", arr)
}
