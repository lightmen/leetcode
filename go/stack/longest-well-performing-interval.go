package stack

func longestWPI(hours []int) int {
	preSum :=[]int{0}
	sum := 0
	for _, h := range hours {
		if h > 8 {
			sum++
		}else {
			sum--
		}

		preSum = append(preSum, sum)
	}

	maxWPI := 0
	for i := 0; i <len(preSum); i++ {
		for j := len(preSum)-1; j > i; j-- {
			if preSum[j] >preSum[i] && j -i  >maxWPI {
				maxWPI = j - i
				break
			}
		}
	}

	return maxWPI
}