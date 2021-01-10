package stack


func reverseParentheses(s string) string {
	var ret string

	st := make([]int32, len(s))
	top := -1

	for _, v := range s {
		if v != ')' {
			top++
			st[top] = v
			continue
		}

		var tmp string
		for top > -1 {
			tc := st[top]
			top--
			if tc == '(' {
				break
			}
			tmp += string(tc)
		}

		for _, c := range tmp {
			top++
			st[top] = c
		}
	}

	for i := 0; i <= top; i++ {
		ret += string(st[i])
	}
	return ret
}