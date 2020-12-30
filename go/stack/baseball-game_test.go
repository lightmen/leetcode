package stack

import "testing"

func TestCalPoints(t *testing.T) {
	ops := []string{"5","2","C","D","+"}

	sum :=  calPoints(ops)
	if sum != 30 {
		t.Fatalf("test failed: %d",sum)
	}

	ops = []string{"5","-2","4","C","D","9","+","+"}
	sum =  calPoints(ops)
	if sum != 27 {
		t.Fatalf("test failed: %d",sum)
	}
}
