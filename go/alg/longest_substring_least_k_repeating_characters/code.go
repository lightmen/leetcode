package longestsubstringleastkrepeatingcharacters

import "strings"

func longestSubstring(s string, k int) (cnt int) {
	if s == "" {
		return
	}

	ch := [26]int{}

	for _, c := range s {
		ch[c-'a']++
	}

	split := byte(0)
	for i, v := range ch {
		if 0 < v && v < k {
			split = 'a' + byte(i)
			break
		}
	}

	if split == 0 {
		return len(s)
	}

	for _, substr := range strings.Split(s, string(split)) {
		cnt = max(cnt, longestSubstring(substr, k))
	}

	return
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
