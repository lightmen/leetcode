package dp

func format(s string) (dstBytes []byte) {
	srcBytes := []byte(s)
	if len(srcBytes) == 0 {
		return
	}

	dstBytes = make([]byte, 0, len(srcBytes)*2+1)

	for i := 0; i < len(srcBytes); i++ {
		dstBytes = append(dstBytes, 0)
		dstBytes = append(dstBytes, srcBytes[i])
	}

	dstBytes = append(dstBytes, 0)
	return
}

func longestPalindrome(s string) string {
	buf := format(s)
	if len(buf) == 0 {
		return ""
	}

	maxC := -1
	maxR := 0

	C := -1                    //最大回文中心点
	R := -1                    //最大回文右边界
	p := make([]int, len(buf)) //p[i] 表示buf数组中，以i下标为中心，最大回文半径

	for i := range buf {
		p[i] = 1
		if R > i {
			p[i] = p[2*C-i]
			if R-i < p[i] {
				p[i] = R - i
			}
		}

		left := i - p[i]
		right := i + p[i]
		for left >= 0 && right < len(buf) {
			if buf[left] != buf[right] {
				break
			}
			p[i]++
			left--
			right++
		}

		if p[i] > maxR {
			maxC = i
			maxR = p[i]
		}

		if i+p[i] >= R {
			C = i
			R = i + p[i] - 1
		}
	}

	retBuf := make([]byte, 0, maxR)
	for i := maxC - maxR + 1; i < maxC+maxR; i++ {
		if buf[i] == 0 {
			continue
		}
		retBuf = append(retBuf, buf[i])
	}

	return string(retBuf)
}
