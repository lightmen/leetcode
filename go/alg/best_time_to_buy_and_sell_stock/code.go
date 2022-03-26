package besttimetobuyandsellstock

func maxProfit(prices []int) int {
	minP := int(^uint(0) >> 1)
	maxVal := 0
	for i := 0; i < len(prices); i++ {
		if prices[i] < minP {
			minP = prices[i]
		}

		if prices[i]-minP > maxVal {
			maxVal = prices[i] - minP
		}
	}

	return maxVal
}
