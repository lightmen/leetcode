package minimumsizesubarraysum

func minSubArrayLen(target int, nums []int) int {
	start, end := 0, 0
	sum := 0
	minSub := len(nums) + 1
	for end < len(nums) {
		sum += nums[end]

		for start <= end && sum >= target {
			if sum >= target && end-start+1 < minSub {
				minSub = end - start + 1
			}
			sum -= nums[start]
			start++
		}

		end++
	}

	if minSub <= len(nums) {
		return minSub
	}

	return 0
}
