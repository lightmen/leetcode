package longest

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	dp := make([]int, len(nums))
	maxLen := 0
	for i, val := range nums {
		dp[i] = 1
		for j := 0; j <= i-1; j++ {
			if val > nums[j] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		maxLen = max(maxLen, dp[i])
	}

	return maxLen
}
