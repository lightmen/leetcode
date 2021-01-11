package stack

import "testing"

func TestCalculate(t *testing.T) {
	s := "1 + 1"
	val := calculate(s)
	if val != 2 {
		t.Fatalf("test failed: %d", val)
	}

	s = "- (3 + (4 + 5))"
	val = calculate(s)
	if val != -12 {
		t.Fatalf("test failed: %d", val)
	}

	s = "-2 +1 "
	val = calculate(s)
	if val != -1 {
		t.Fatalf("test failed: %d", val)
	}

	s = "1 * 5"
	val = calculate(s)
	if val != 5 {
		t.Fatalf("test failed: %d", val)
	}

	s = "2-1 + 2 "
	val = calculate(s)
	if val != 3 {
		t.Fatalf("test failed: %d", val)
	}

	s = "(1+(4+5+2)-3)+(6+8)"
	val = calculate(s)
	if val != 23 {
		t.Fatalf("test failed: %d", val)
	}
}
