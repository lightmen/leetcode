package poweroffour

func isPowerOfFour(n int) bool {
	if n <= 0 {
		return false
	}

	if n&(n-1) != 0 {
		return false
	}

	return n&0xaaaaaaaa == 0
}
