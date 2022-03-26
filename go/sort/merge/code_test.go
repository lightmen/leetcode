package merge

import (
	"reflect"
	"testing"
)

func TestMergeSort(t *testing.T) {
	arr := []int{1, 6, 5, 4}
	mergeSort(arr)
	expect := []int{1, 4, 5, 6}
	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}

	arr = []int{1, 7, 3, 5, 3, 6, 9}
	mergeSort(arr)
	expect = []int{1, 3, 3, 5, 6,7, 9}
	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}


	arr = []int{1,1}
	mergeSort(arr)
	expect = []int{1,1}
	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}
}

