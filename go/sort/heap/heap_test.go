package heap

import "testing"

func TestSort(t *testing.T) {
	arr := []int{3, -1, 45, 3, 5, 98, 12, 2, 10}
	sort(arr)
	t.Logf("%v", arr)
}
