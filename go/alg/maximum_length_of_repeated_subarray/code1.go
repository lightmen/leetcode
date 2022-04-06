package maximum

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func maxLength(nums1, nums2 []int, add1, add2, ln int) int {
	cnt := 0
	maxCnt := 0
	for i := 0; i < ln; i++ {
		if nums1[add1+i] != nums2[add2+i] {
			cnt = 0
		} else {
			cnt++
			maxCnt = max(maxCnt, cnt)
		}
	}

	return maxCnt
}

func findLength(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	maxLen := 0
	for i := 0; i < m; i++ {
		ln := min(m-i, n)
		maxLen = max(maxLen, maxLength(nums1, nums2, i, 0, ln))
	}

	for i := 0; i < n; i++ {
		ln := min(n-i, m)
		maxLen = max(maxLen, maxLength(nums1, nums2, 0, i, ln))
	}

	return maxLen
}
