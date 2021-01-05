package stack

import "testing"

func TestBackspaceCompare(t *testing.T) {
	S := "ab#c"
	T := "ad#c"
	if !backspaceCompare(S, T) {
		t.Fatalf("test failed ")
	}

	S = "ab##"
	T = "c#d#"
	if !backspaceCompare(S, T) {
		t.Fatalf("test failed ")
	}


	S = "a##c"
	T = "#a#c"
	if !backspaceCompare(S, T) {
		t.Fatalf("test failed ")
	}


	S = "a#c"
	T = "b"
	if backspaceCompare(S, T) {
		t.Fatalf("test failed ")
	}
}
