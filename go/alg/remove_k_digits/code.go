package removekdigits

import "strings"

func removeKdigits(num string, k int) string {
	st := make([]byte, len(num))
	top := -1

	for i := 0; i < len(num); i++ {
		for k > 0 && top > -1 && num[i] < st[top] {
			k--
			top--
		}
		top++
		st[top] = num[i]
	}

	st = st[:top-k+1]
	s := strings.TrimLeft(string(st), "0")
	if s == "" {
		s = "0"
	}

	return s
}
