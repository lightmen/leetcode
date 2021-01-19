package basic_calculator_ii

import (
	"testing"
)

func TestCalculate(t *testing.T) {
	s := "12-3*4"
	val := calculate(s)
	if val != 0 {
		t.Fatalf("test failed: %d", val)
	}

	s = " -3 +2*2 "
	val = calculate(s)
	if val != 1 {
		t.Fatalf("test failed: %d", val)
	}

	s = " 3/2 "
	val = calculate(s)
	if val != 1 {
		t.Fatalf("test failed: %d", val)
	}

	s = "3+5 / 2"
	val = calculate(s)
	if val != 5 {
		t.Fatalf("test failed: %d", val)
	}

	s = "35"
	val = calculate(s)
	if val != 35 {
		t.Fatalf("test failed: %d", val)
	}
}
