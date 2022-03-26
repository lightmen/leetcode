package palindrome_number

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	tmp := x
	val := 0
	for tmp > 0 {
		remain := tmp % 10
		tmp /= 10
		val = val*10 + remain
	}

	return val == x
}
