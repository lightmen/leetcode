package minimumsizesubarraysum

import "testing"

func TestMinSubArrayLen(t *testing.T) {
	nums := []int{2, 3, 1, 2, 4, 3}
	sub := minSubArrayLen(7, nums)

	t.Logf("%d", sub)
}
