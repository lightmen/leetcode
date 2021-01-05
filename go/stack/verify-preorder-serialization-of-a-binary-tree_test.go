package stack

import "testing"

func TestIsValidSerialization(t *testing.T) {
	preorder := "9,3,4,#,#,1,#,#,2,#,6,#,#"
	if !isValidSerialization(preorder) {
		t.Fatalf("test failed")
	}

	preorder = "1,#"
	if isValidSerialization(preorder) {
		t.Fatalf("test failed")
	}

	preorder = "9,#,#,1"
	if isValidSerialization(preorder) {
		t.Fatalf("test failed")
	}

	preorder = "9,3,4,#,#,1,#,#,#,2,#,6,#,#"
	if isValidSerialization(preorder) {
		t.Fatalf("test failed")
	}
}
