package stack

import "testing"

func TestIsValid(t *testing.T) {
	s := ""
	if ok := isValid(s); !ok {
		t.Fatalf("test failed: %s", s)
	}

	s = "{{(){}[]}}"
	if ok := isValid(s); !ok {
		t.Fatalf("test failed: %s", s)
	}

	s = "{{(){}[]}}}"
	if ok := isValid(s); ok {
		t.Fatalf("test failed: %s", s)
	}
}
