package longest_palindromic_substring

//manacher算法
func toManacher(src string) []byte {
	srcBuf := []byte(src)
	dstBuf := make([]byte, 0)
	for _, val := range srcBuf {
		dstBuf = append(dstBuf, 0)
		dstBuf = append(dstBuf, val)
	}
	if len(dstBuf) > 0 {
		dstBuf = append(dstBuf, 0)
	}

	return dstBuf
}

func longestPalindrome(s string) (ret string) {
	buf := toManacher(s)

	pArr := make([]int, len(buf))
	R := -1 //回文右边界
	C := -1 //中心

	maxIdx := 0 //最大回文子串 中心下标
	maxLen := 0 //最大回文子串长度

	for idx := range buf {
		pArr[idx] = 1
		if R >= idx {
			pLen := R - idx + 1
			if pArr[2*C-R] < pLen {
				pLen = pArr[2*C-R]
			}
		}

		left := idx - pArr[idx]
		right := idx + pArr[idx]
		for left >= 0 && right < len(buf) {
			if buf[left] != buf[right] {
				break
			}
			pArr[idx]++
			left--
			right++
		}

		if idx + pArr[idx] >= R {
			R = pArr[idx] - 1
			C = idx
		}

		if pArr[idx] > maxLen {
			maxLen = pArr[idx]
			maxIdx = idx
		}
	}

	dstBuf := make([]byte, 0)
	for i := maxIdx - maxLen + 1; i <= maxIdx + maxLen -1; i++ {
		if buf[i] != 0 {
			dstBuf = append(dstBuf, buf[i])
		}
	}

	return string(dstBuf)
}
