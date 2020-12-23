package stack

import "testing"

func TestLongestWPI(t *testing.T) {
	arr := []int{9,9,6,0,6,6,9}

	wpi := longestWPI(arr)
	if wpi != 3 {
		t.Fatalf("test failed:%d", wpi)
	}

	arr = []int{6,9,9}
	wpi = longestWPI(arr)
	if wpi != 3 {
		t.Fatalf("test failed:%d", wpi)
	}

	arr = []int{9,6, 9}

	wpi = longestWPI(arr)
	if wpi != 3 {
		t.Fatalf("test failed:%d", wpi)
	}
}
