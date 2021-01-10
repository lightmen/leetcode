package stack

import "testing"

func TestExclusiveTime(t *testing.T)  {
	n := 2
	logs := []string {
		"0:start:0",
		"1:start:2",
		"1:end:5",
		"0:end:6",
	}

	arr := exclusiveTime(n, logs)
	if arr[0] != 3 || arr[1] != 4 {
		t.Fatalf("test failed: %+v", arr)
	}
}
