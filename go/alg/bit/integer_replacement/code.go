package integer

func min(a, b int) int {
	if a > b {
		return b
	}

	return a
}

func integerReplacement(n int) int {
	if n == 1 {
		return 0
	}

	if n%2 == 0 {
		return 1 + integerReplacement(n/2)
	}

	return 2 + min(integerReplacement((n+1)/2), integerReplacement((n-1)/2))
}
