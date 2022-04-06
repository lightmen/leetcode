package maximumsubarray

import "math"

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func maxSubArray(nums []int) int {
	maxSum := math.MinInt

	sum := 0
	for _, val := range nums {
		sum += val
		maxSum = max(maxSum, sum)
		if sum < 0 {
			sum = 0
		}
	}

	return maxSum
}
