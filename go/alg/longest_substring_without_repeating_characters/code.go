package longest_substring

func lengthOfLongestSubstring(s string) int {
	flag := make(map[byte]struct{})
	start, end := 0, 0
	maxSub := 0
	for start < len(s) {
		for end < len(s) {
			if _, ok := flag[s[end]]; ok {
				break
			}
			flag[s[end]] = struct{}{}
			if end-start+1 > maxSub {
				maxSub = end - start + 1
			}
			end++
		}

		delete(flag, s[start])
		start++
	}

	return maxSub
}
