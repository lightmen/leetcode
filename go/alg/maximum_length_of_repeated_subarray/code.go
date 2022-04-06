package maximum

func max1(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func findLength1(nums1 []int, nums2 []int) int {
	ret := 0

	m := len(nums1)
	n := len(nums2)

	dp := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]int, n+1)
	}

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if nums1[i] == nums2[j] {
				dp[i][j] = dp[i+1][j+1] + 1
				ret = max1(ret, dp[i][j])
			} else {
				dp[i][j] = 0
			}

		}
	}

	return ret
}
