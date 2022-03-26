package quick

import (
	"math/rand"
	"reflect"
	"testing"
)

func TestQickSort(t *testing.T) {
	arr := []int{1, 6, 5, 4}
	quickSort(arr)
	expect := []int{1, 4, 5, 6}
	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}

	arr = []int{1, 7, 3, 5, 3, 6, 9}
	quickSort(arr)
	expect = []int{1, 3, 3, 5, 6, 7, 9}
	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}

	arr = []int{1, 1}
	quickSort(arr)
	expect = []int{1, 1}
	if !reflect.DeepEqual(arr, expect) {
		t.Fatalf("test failed:%v", arr)
	}

	for i := 0; i < 1000; i++ {
		cnt := 50 + rand.Intn(300)
		nums := make([]int, cnt)
		for j := 0; j < len(nums); j++ {
			nums[j] = rand.Intn(cnt + 100)
		}

		quickSort(nums)

		for j := 1; j < len(nums); j++ {
			if nums[j] < nums[j-1] {
				t.Fatalf("test failed:%v", nums)
			}
		}
	}

}
