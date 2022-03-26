package permutations

import "testing"

func TestPermute(t *testing.T) {
	nums := []int{1, 2, 3}
	arrList := permute(nums)
	t.Logf("%v", arrList)
}
