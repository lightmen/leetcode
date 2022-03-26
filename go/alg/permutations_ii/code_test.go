package permutationii

import "testing"

func TestPermuteUnique(t *testing.T) {
	nums := []int{2, 1, 1, 2}
	arrList := permuteUnique(nums)

	t.Logf("%v", arrList)

	nums = []int{1, 2, 3}
	arrList = permuteUnique(nums)

	t.Logf("%v", arrList)
}
