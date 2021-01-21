package stack

import "testing"

func TestMostCompetitive(t *testing.T) {
	nums := []int{3,5,2,6}
	k := 2
	target := []int{2, 6}
	result := mostCompetitive(nums, k)

	if len(target) != len(result) {
		t.Fatalf("tesst failed, %+v : %+v", target, result)
	}

	for idx, val := range target {
		if result[idx] != val {
			t.Fatalf("test failed, %d:%d", idx, result[idx])
		}
	}


	nums = []int{2,4,3,3,5,4,9,6}
	k = 4
	target = []int{2,3,3,4}
	result = mostCompetitive(nums, k)
	if len(target) != len(result) {
		t.Fatalf("tesst failed, %+v : %+v", target, result)
	}

	for idx, val := range target {
		if result[idx] != val {
			t.Fatalf("test failed, %d:%d", idx, result[idx])
		}
	}
}
