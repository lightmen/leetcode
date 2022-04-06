package containsduplicateiii

import "testing"

func TestContainsNearbyAlmostDuplicate(t *testing.T) {
	nums := []int{-3, 3, -6}
	k := 2
	m := 3
	ok := containsNearbyAlmostDuplicate(nums, k, m)
	t.Logf("%v\n", ok)
}
