package stack

import "testing"

func TestScoreOfParentheses(t *testing.T) {
	S := "()"
	val := scoreOfParentheses(S)
	if val != 1 {
		t.Fatalf("test failed: %d", val)
	}

	S = "(())"
	val = scoreOfParentheses(S)
	if val != 2 {
		t.Fatalf("test failed: %d", val)
	}

	S = "()()"
	val = scoreOfParentheses(S)
	if val != 2 {
		t.Fatalf("test failed: %d", val)
	}

	S = "(()(()))"
	val = scoreOfParentheses(S)
	if val != 6 {
		t.Fatalf("test failed: %d", val)
	}

}