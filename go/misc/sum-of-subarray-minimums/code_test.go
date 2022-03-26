package sum_of_subarray_minimums

import "testing"

func TestSumSubarrayMins(t *testing.T) {
	arr := []int{3,1,2,4}
	result := sumSubarrayMins(arr)
	expect := 17
	if result !=expect {
		t.Fatalf("test failed: %d", result)
	}

	arr = []int{71,55,82,55}
	result = sumSubarrayMins(arr)
	expect = 593
	if result !=expect {
		t.Fatalf("test failed: %d", result)
	}

	arr = []int{1,2,1}
	result = sumSubarrayMins(arr)
	expect = 4
	if result !=expect {
		t.Fatalf("test failed: %d", result)
	}
}
