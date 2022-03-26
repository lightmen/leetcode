package heap

import (
	"reflect"
	"testing"
)

func TestHeapSort(t *testing.T) {
	arr := []int{1, 7, 3, 5, 3, 6,9}
	heapSort(arr)
	expect := []int{1, 3, 3, 5, 6, 7, 9}

	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}


	arr = []int{1,1}
	heapSort(arr)
	expect = []int{1,1}

	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}
}
