package hammingdistance

func hammingDistance(x int, y int) int {
	val := x ^ y
	cnt := 0
	for val > 0 {
		cnt += val & 0x1
		val >>= 1
	}

	return cnt
}
