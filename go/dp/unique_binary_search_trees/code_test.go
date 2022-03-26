package unique_binary_search_trees

import "testing"

func TestNumTrees(t *testing.T) {
	val := numTrees(3)
	if val != 5 {
		t.Fatalf("test failed: %d", val)
	}
}
