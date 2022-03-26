package nextpermutation

import "testing"

func TestNextPermutation(t *testing.T) {
	nums := []int{1, 3, 2}
	nextPermutation(nums)
	t.Logf("%v", nums)
}
